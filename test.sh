set -e

function assert() {
    OUT=$(./test $1 $2)

    if [ "$OUT" != "$3" ]; then
	echo "ex0$1 test failed !['$2' => '$OUT' != '$3']"
	exit 1
    fi
}

gcc -Wall -Wextra -Werror -o test main.c

# ex00
assert 0 a a
assert 0 : :
assert 0 1 1
assert 0 + +
assert 0 2 2

# ex01/02/03
assert 1 _ "abcdefghijklmnopqrstuvwxyz"
assert 2 _ "zyxwvutsrqponmlkjihgfedcba"
assert 3 _ "0123456789"

# # ex04
assert 4 12 P
assert 4 1 P
assert 4 54389547 P
assert 4 -2147483648 N
assert 4 2147483647 P
assert 4 -12 N

# # ex05
assert 5 _ "012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789"

# # ex07
assert 7 12 12
assert 7 1 1
assert 7 54389547 54389547
assert 7 -2147483648 -2147483648
assert 7 2147483647 2147483647
assert 7 -12 -12
assert 7 0 0

echo "Test passed successfully for ex0[0/1/2/3/4/5/7]!"
