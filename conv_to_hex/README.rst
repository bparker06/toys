========================================================================
      Conversion numbers to hexadecimal representation
========================================================================

For details see `full article`__.

__ http://0x80.pl/articles/convert-to-hex.html



Introduction
------------------------------------------------------------------------

Expand is a procedure that expands nibbles to bytes::

    0x00ab => 0x0a0b

Expand procedures:

- **naive** - shifts and bit-or;
- **mul** - replaces two shifts and one bit-or with one multiplication;
- **simd** - SSE instructions (``punpcklbw``, shift and bit-and).

Convert is a procedure that produces an ASCII representation of an expanded
nibbles::

    0x0b0a => "ab"

Convert procedures:

- **naive** - convert byte-by-byte;
- **swar** - convert whole register at once using standard CPU instructions;
- **simd**  - convert whole register at once using SSE instructions.


Programs
------------------------------------------------------------------------

Two programs are produced by make:

* ``verify`` --- tests correctness of all procedures
* ``speedup`` --- measure speedup for different combination of expand &
  convert procedures.

Results from Pentium M
------------------------------------------------------------------------

+------------+------------+------------+------------+------------------------------+
| expand     | convert    |   time [s] |    speedup |                              |
+============+============+============+============+==============================+
|      naive |      naive |     0.4789 |       1.00 | ``████████``                 |
+------------+------------+------------+------------+------------------------------+
|      naive |       swar |     0.1533 |       3.12 | ``████████████████████████`` |
+------------+------------+------------+------------+------------------------------+
|      naive |       simd |     0.1884 |       2.54 | ``████████████████████``     |
+------------+------------+------------+------------+------------------------------+
|        mul |      naive |     0.4629 |       1.03 | ``████████``                 |
+------------+------------+------------+------------+------------------------------+
|        mul |       swar |     0.1621 |       2.96 | ``███████████████████████``  |
+------------+------------+------------+------------+------------------------------+
|        mul |       simd |     0.1905 |       2.51 | ``████████████████████``     |
+------------+------------+------------+------------+------------------------------+
|       simd |      naive |     0.4680 |       1.02 | ``████████``                 |
+------------+------------+------------+------------+------------------------------+
|       simd |       swar |     0.1625 |       2.95 | ``███████████████████████``  |
+------------+------------+------------+------------+------------------------------+
|       simd |       simd |     0.2037 |       2.35 | ``██████████████████``       |
+------------+------------+------------+------------+------------------------------+
