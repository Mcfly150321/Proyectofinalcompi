#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char vars[100][32];
int total_vars = 0;

char temp_eax[32] = "";
char temp_ecx[32] = "";
char var_en_eax[32] = "";
char var_en_ecx[32] = "";
int flags_listas_jnz = 0;
int is_bool_eax = 0;
int is_bool_ecx = 0;

void agregar_var(const char *v) {
    for (int i = 0; i < total_vars; i++) {
        if (strcmp(vars[i], v) == 0) return;
    }
    strcpy(vars[total_vars++], v);
}

int es_numero(const char *s) {
    if (*s == '-' || *s == '+') s++;
    if (!*s) return 0;
    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

int es_temp(const char *s) {
    if (s[0] != 't') return 0;
    int i = 1;
    if (!s[i]) return 0;
    while (s[i]) {
        if (!isdigit(s[i])) return 0;
        i++;
    }
    return 1;
}

char* op_asm(const char *s) {
    static char buf[64];
    if (strcmp(s, temp_eax) == 0) {
        return "eax";
    }
    if (strcmp(s, temp_ecx) == 0) {
        return "ecx";
    }
    if (es_numero(s)) {
        sprintf(buf, "%s", s);
    } else {
        sprintf(buf, "[%s]", s);
    }
    return buf;
}

void limpiar(char *s) {
    int i = 0, j = 0;
    while (s[i]) {
        if (s[i] != ';' && s[i] != '\r' && s[i] != '\n') {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}

void emitir_cmp(FILE *out, const char *izq, const char *op1, const char *op2, const char *set_inst, const char *op_simb) {
    const char *reg32 = "eax";
    const char *reg8 = "al";

    fprintf(out, "\n    ; condicion: %s %s %s\n", op1, op_simb, op2);

    if (temp_eax[0] != '\0' && strcmp(op1, temp_eax) != 0 && strcmp(op2, temp_eax) != 0) {
        reg32 = "ecx";
        reg8 = "cl";
        strcpy(temp_ecx, izq);
        is_bool_ecx = 1;
        if (strcmp(var_en_ecx, op1) != 0 && strcmp(op1, "ecx") != 0) {
            fprintf(out, "    mov ecx, %s\n", op_asm(op1));
        }
    } else {
        strcpy(temp_eax, izq);
        is_bool_eax = 1;
        if (strcmp(var_en_eax, op1) != 0 && strcmp(op1, "eax") != 0) {
            fprintf(out, "    mov eax, %s\n", op_asm(op1));
        }
    }

    fprintf(out, "    cmp %s, %s\n", reg32, op_asm(op2));
    fprintf(out, "    %s %s\n", set_inst, reg8);
    flags_listas_jnz = 0;
    var_en_eax[0] = '\0';
    var_en_ecx[0] = '\0';
}

void emitir_potencia(FILE *out, const char *izq, const char *op1, const char *op2) {
    static int num_pow = 1;
    int p_id = num_pow++;

    fprintf(out, "\n    ; potencia: %s = %s ** %s\n", izq, op1, op2);

    if (strcmp(op2, temp_eax) == 0 && strcmp(op1, temp_ecx) == 0) {
        fprintf(out, "    mov edx, eax\n");
        fprintf(out, "    mov ebx, ecx\n");
        fprintf(out, "    mov ecx, edx\n");
    } else if (strcmp(op1, temp_eax) == 0) {
        fprintf(out, "    mov ebx, eax\n");
        fprintf(out, "    mov ecx, %s\n", op_asm(op2));
    } else if (strcmp(op2, temp_eax) == 0) {
        fprintf(out, "    mov edx, eax\n");
        fprintf(out, "    mov ebx, %s\n", op_asm(op1));
        fprintf(out, "    mov ecx, edx\n");
    } else {
        if (strcmp(var_en_eax, op1) == 0) {
            fprintf(out, "    mov ebx, eax\n");
        } else {
            fprintf(out, "    mov ebx, %s\n", op_asm(op1));
        }
        fprintf(out, "    mov ecx, %s\n", op_asm(op2));
    }

    fprintf(out, "    mov eax, 1\n");
    fprintf(out, "pow_loop_%d:\n", p_id);
    fprintf(out, "    cmp ecx, 0\n");
    fprintf(out, "    jle pow_end_%d\n", p_id);
    fprintf(out, "    imul eax, ebx\n");
    fprintf(out, "    dec ecx\n");
    fprintf(out, "    jmp pow_loop_%d\n", p_id);
    fprintf(out, "pow_end_%d:\n\n", p_id);

    strcpy(temp_eax, izq);
    temp_ecx[0] = '\0';
    var_en_eax[0] = '\0';
    var_en_ecx[0] = '\0';
    is_bool_eax = 0;
    is_bool_ecx = 0;
    flags_listas_jnz = 0;
}

void emitir_arit(FILE *out, const char *izq, const char *op1, const char *op2, const char *inst) {
    if (strcmp(op1, temp_eax) == 0 && strcmp(op2, temp_ecx) == 0) {
        if (strcmp(inst, "and") == 0 || strcmp(inst, "or") == 0) {
            fprintf(out, "    ; operar %s\n", inst);
            fprintf(out, "    %s al, cl\n", inst);
            flags_listas_jnz = 1;
            is_bool_eax = 1;
        } else {
            fprintf(out, "    %s eax, ecx\n", inst);
            flags_listas_jnz = 0;
            is_bool_eax = 0;
        }
        strcpy(temp_eax, izq);
        temp_ecx[0] = '\0';
        is_bool_ecx = 0;
        var_en_eax[0] = '\0';
        var_en_ecx[0] = '\0';
        return;
    }
    if (strcmp(op1, temp_eax) == 0) {
        fprintf(out, "    %s eax, %s\n", inst, op_asm(op2));
        strcpy(temp_eax, izq);
        flags_listas_jnz = 0;
        is_bool_eax = 0;
        var_en_eax[0] = '\0';
        return;
    }
    if (strcmp(op2, temp_eax) == 0) {
        fprintf(out, "    mov ecx, eax\n");
        if (strcmp(var_en_eax, op1) != 0) {
            fprintf(out, "    mov eax, %s\n", op_asm(op1));
        }
        fprintf(out, "    %s eax, ecx\n", inst);
        strcpy(temp_eax, izq);
        temp_ecx[0] = '\0';
        flags_listas_jnz = 0;
        is_bool_eax = 0;
        is_bool_ecx = 0;
        var_en_eax[0] = '\0';
        var_en_ecx[0] = '\0';
        return;
    }
    if (temp_eax[0] != '\0') {
        if (strcmp(var_en_ecx, op1) != 0) {
            fprintf(out, "    mov ecx, %s\n", op_asm(op1));
        }
        fprintf(out, "    %s ecx, %s\n", inst, op_asm(op2));
        strcpy(temp_ecx, izq);
        flags_listas_jnz = 0;
        is_bool_ecx = 0;
        var_en_ecx[0] = '\0';
    } else {
        if (strcmp(var_en_eax, op1) != 0) {
            fprintf(out, "    mov eax, %s\n", op_asm(op1));
        }
        fprintf(out, "    %s eax, %s\n", inst, op_asm(op2));
        strcpy(temp_eax, izq);
        flags_listas_jnz = 0;
        is_bool_eax = 0;
        var_en_eax[0] = '\0';
    }
}

int main(int argc, char **argv) {
    char *nom_in = "codigo_tdc.txt";
    char *nom_out = "salida.asm";

    if (argc > 1) nom_in = argv[1];
    if (argc > 2) nom_out = argv[2];

    FILE *in = fopen(nom_in, "r");
    if (!in) {
        printf("Error: no se pudo abrir %s\n", nom_in);
        return 1;
    }

    FILE *out = fopen(nom_out, "w");
    if (!out) {
        printf("Error: no se pudo crear %s\n", nom_out);
        fclose(in);
        return 1;
    }

    char linea[256];
    int usa_in = 0;
    int usa_out = 0;

    while (fgets(linea, sizeof(linea), in)) {
        char v[32];
        if (sscanf(linea, " DECL %s", v) == 1 || sscanf(linea, "DECL %s", v) == 1) {
            limpiar(v);
            agregar_var(v);
        }
        if (strstr(linea, "call input") != NULL) usa_in = 1;
        if (strstr(linea, "call output") != NULL) usa_out = 1;
    }

    if (usa_in || usa_out) {
        fprintf(out, "section .data\n");
        if (usa_in) fprintf(out, "    fmt_in db \"%%d\", 0\n");
        if (usa_out) fprintf(out, "    fmt_out db \"%%d\", 10, 0\n");
        fprintf(out, "\n");
    }

    fprintf(out, "section .bss\n");
    for (int i = 0; i < total_vars; i++) {
        fprintf(out, "    %s resd 1\n", vars[i]);
    }
    fprintf(out, "\nsection .text\n");
    fprintf(out, "    global _start\n");
    if (usa_out) fprintf(out, "    extern printf\n");
    if (usa_in) fprintf(out, "    extern scanf\n");
    fprintf(out, "\n");

    rewind(in);

    while (fgets(linea, sizeof(linea), in)) {
        char copia[256];
        strcpy(copia, linea);
        limpiar(copia);

        char *p = copia;
        while (*p == ' ' || *p == '\t') p++;
        if (!*p || strncmp(p, "DECL", 4) == 0) continue;

        if (strcmp(p, "main:") == 0) { /*esto es main porque el tdc imprime main en su bloque, por eso comparamos con el bloque main*/
            fprintf(out, "_start:\n\n");
            continue;
        }

        if (p[0] == 'l' && isdigit(p[1]) && p[strlen(p)-1] == ':') {
            fprintf(out, "\n%s\n", p);
            temp_eax[0] = '\0';
            temp_ecx[0] = '\0';
            var_en_eax[0] = '\0';
            var_en_ecx[0] = '\0';
            continue;
        }

        char destino[32];
        if (sscanf(p, "jmp %s", destino) == 1 || sscanf(p, "goto %s", destino) == 1) {
            limpiar(destino);
            if (destino[strlen(destino)-1] == ':') destino[strlen(destino)-1] = '\0';
            fprintf(out, "    jmp %s\n\n", destino);
            temp_eax[0] = '\0';
            temp_ecx[0] = '\0';
            var_en_eax[0] = '\0';
            var_en_ecx[0] = '\0';
            continue;
        }

        char cond_temp[32], lbl[32];
        if (sscanf(p, "ifnz %s goto %s", cond_temp, lbl) == 2) {
            limpiar(lbl);
            if (lbl[strlen(lbl)-1] == ':') lbl[strlen(lbl)-1] = '\0';
            if (!flags_listas_jnz) {
                fprintf(out, "    test al, al\n");
            }
            fprintf(out, "    jnz %s    ; salta si se cumple\n\n", lbl);
            flags_listas_jnz = 0;
            temp_eax[0] = '\0';
            temp_ecx[0] = '\0';
            var_en_eax[0] = '\0';
            var_en_ecx[0] = '\0';
            continue;
        }
        if (sscanf(p, "ifz %s goto %s", cond_temp, lbl) == 2) {
            limpiar(lbl);
            if (lbl[strlen(lbl)-1] == ':') lbl[strlen(lbl)-1] = '\0';
            if (!flags_listas_jnz) {
                fprintf(out, "    test al, al\n");
            }
            fprintf(out, "    jz %s    ; salta si no se cumple\n\n", lbl);
            flags_listas_jnz = 0;
            temp_eax[0] = '\0';
            temp_ecx[0] = '\0';
            var_en_eax[0] = '\0';
            var_en_ecx[0] = '\0';
            continue;
        }

        static char pend_push[32] = "";
        char var_io[32];

        if (strncmp(p, "push ", 5) == 0) {
            if (sscanf(p + 5, "%s", pend_push) == 1) {
                limpiar(pend_push);
            }
            continue;
        }

        if (strstr(p, "call output") != NULL) {
            char var_inline[32];
            if (sscanf(p, "push %[^;]", var_inline) == 1) {
                limpiar(var_inline);
                strcpy(pend_push, var_inline);
            }
            if (pend_push[0] != '\0') {
                fprintf(out, "    push dword %s\n", op_asm(pend_push));
                fprintf(out, "    push fmt_out\n");
                fprintf(out, "    call printf\n");
                fprintf(out, "    add esp, 8\n\n");
                pend_push[0] = '\0';
            }
            temp_eax[0] = '\0';
            temp_ecx[0] = '\0';
            var_en_eax[0] = '\0';
            var_en_ecx[0] = '\0';
            continue;
        }

        if (strstr(p, "call input") != NULL) {
            char *pop_pos = strstr(p, "pop ");
            if (pop_pos && sscanf(pop_pos + 4, "%s", var_io) == 1) {
                limpiar(var_io);
                fprintf(out, "    push %s\n", var_io);
                fprintf(out, "    push fmt_in\n");
                fprintf(out, "    call scanf\n");
                fprintf(out, "    add esp, 8\n\n");
                temp_eax[0] = '\0';
                temp_ecx[0] = '\0';
                var_en_eax[0] = '\0';
                var_en_ecx[0] = '\0';
            }
            continue;
        }

        if (strncmp(p, "pop ", 4) == 0) {
            if (sscanf(p + 4, "%s", var_io) == 1) {
                limpiar(var_io);
                fprintf(out, "    push %s\n", var_io);
                fprintf(out, "    push fmt_in\n");
                fprintf(out, "    call scanf\n");
                fprintf(out, "    add esp, 8\n\n");
                temp_eax[0] = '\0';
                temp_ecx[0] = '\0';
                var_en_eax[0] = '\0';
                var_en_ecx[0] = '\0';
            }
            continue;
        }

        char *eq = strchr(p, '=');
        if (eq) {
            *eq = '\0';
            char izq[32], der[64];
            strcpy(izq, p);
            strcpy(der, eq + 1);

            char *c = izq + strlen(izq) - 1;
            while (c >= izq && (*c == ' ' || *c == '\t')) *c-- = '\0';
            char *d = der;
            while (*d == ' ' || *d == '\t') d++;

            char op1[32], op2[32];
            char *sub_pos = (*d != '\0') ? strchr(d + 1, '-') : NULL;

            if (strstr(d, "<=")) {
                sscanf(d, "%[^<=]<=%s", op1, op2);
                emitir_cmp(out, izq, op1, op2, "setle", "<=");
            } else if (strstr(d, ">=")) {
                sscanf(d, "%[^>=]>=%s", op1, op2);
                emitir_cmp(out, izq, op1, op2, "setge", ">=");
            } else if (strstr(d, "==")) {
                sscanf(d, "%[^==]==%s", op1, op2);
                emitir_cmp(out, izq, op1, op2, "sete", "==");
            } else if (strstr(d, "!=")) {
                sscanf(d, "%[^!=]!=%s", op1, op2);
                emitir_cmp(out, izq, op1, op2, "setne", "!=");
            } else if (strstr(d, "<>")) {
                sscanf(d, "%[^<>]<>%s", op1, op2);
                emitir_cmp(out, izq, op1, op2, "setne", "<>");
            } else if (strchr(d, '<')) {
                sscanf(d, "%[^<]<%s", op1, op2);
                emitir_cmp(out, izq, op1, op2, "setl", "<");
            } else if (strchr(d, '>')) {
                sscanf(d, "%[^>]>%s", op1, op2);
                emitir_cmp(out, izq, op1, op2, "setg", ">");
            } else if (strstr(d, "&&")) {
                sscanf(d, "%[^&]&&%s", op1, op2);
                emitir_arit(out, izq, op1, op2, "and");
            } else if (strstr(d, "||")) {
                sscanf(d, "%[^|]||%s", op1, op2);
                emitir_arit(out, izq, op1, op2, "or");
            } else if (strchr(d, '+')) {
                sscanf(d, "%[^+]+%s", op1, op2);
                emitir_arit(out, izq, op1, op2, "add");
            } else if (sub_pos != NULL) {
                int len1 = sub_pos - d;
                strncpy(op1, d, len1);
                op1[len1] = '\0';
                strcpy(op2, sub_pos + 1);
                emitir_arit(out, izq, op1, op2, "sub");
            } else if (strstr(d, "**")) {
                sscanf(d, "%[^*]**%s", op1, op2);
                emitir_potencia(out, izq, op1, op2);
            } else if (strchr(d, '*')) {
                sscanf(d, "%[^*]*%s", op1, op2);
                emitir_arit(out, izq, op1, op2, "imul");
            } else if (strchr(d, '/')) {
                sscanf(d, "%[^/]/%s", op1, op2);
                if (strcmp(op2, temp_eax) == 0) {
                    fprintf(out, "    mov ecx, eax\n");
                    if (strcmp(var_en_eax, op1) != 0) {
                        fprintf(out, "    mov eax, %s\n", op_asm(op1));
                    }
                } else {
                    if (strcmp(op1, temp_eax) != 0) {
                        fprintf(out, "    mov eax, %s\n", op_asm(op1));
                    }
                    fprintf(out, "    mov ecx, %s\n", op_asm(op2));
                }
                fprintf(out, "    cdq\n");
                fprintf(out, "    idiv ecx\n");
                strcpy(temp_eax, izq);
                temp_ecx[0] = '\0';
                var_en_eax[0] = '\0';
                var_en_ecx[0] = '\0';
            } else {
                if (es_temp(d)) {
                    if (strcmp(d, temp_ecx) == 0) {
                        if (is_bool_ecx) {
                            fprintf(out, "    movzx ecx, cl\n");
                            is_bool_ecx = 0;
                        }
                        fprintf(out, "    mov [%s], ecx\n", izq);
                        strcpy(var_en_ecx, izq);
                        temp_ecx[0] = '\0';
                    } else {
                        if (is_bool_eax) {
                            fprintf(out, "    movzx eax, al\n");
                            is_bool_eax = 0;
                        }
                        fprintf(out, "    mov [%s], eax\n", izq);
                        strcpy(var_en_eax, izq);
                        temp_eax[0] = '\0';
                    }
                } else if (es_numero(d)) {
                    fprintf(out, "    mov dword [%s], %s\n", izq, d);
                    if (strcmp(var_en_eax, izq) == 0) var_en_eax[0] = '\0';
                    if (strcmp(var_en_ecx, izq) == 0) var_en_ecx[0] = '\0';
                } else {
                    if (strcmp(var_en_eax, d) != 0) {
                        fprintf(out, "    mov eax, [%s]\n", d);
                    }
                    fprintf(out, "    mov [%s], eax\n", izq);
                    strcpy(var_en_eax, izq);
                    temp_eax[0] = '\0';
                }
            }
        }
    }

    fprintf(out, "\n    ; Salida del programa\n");
    fprintf(out, "    mov eax, 1 \n");
    fprintf(out, "    xor ebx, ebx \n");
    fprintf(out, "    int 0x80 \n");

    fclose(in);
    fclose(out);
    return 0;
}
