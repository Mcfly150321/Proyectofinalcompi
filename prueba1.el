*** programa de prueba ***
MAIN
BEGIN
  x:y:z ALLOCATE;
  INPUT x;
  INPUT y;
  z := 1 + x;
  IF (x < y AND x > 0 OR y == 3) THEN
  BEGIN
    IF (x == 10) THEN
    BEGIN
      z := 2 ** x;
    END
    ELSE
    BEGIN
      z := -5;
    END
  END
  ELSE
  BEGIN
    z := 0;
  END
  FOR i := 1 TO y DO
  BEGIN
    z := z + 1;
  END
  DO
    z := z - 1;
  WHILE (z > 0)
  OUTPUT z;
END
