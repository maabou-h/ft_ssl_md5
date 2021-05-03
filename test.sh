echo "openssl:"
echo -n "" | openssl md5
echo -n "hello" | openssl md5
echo -n " " | openssl md5
cat main.c | openssl md5
openssl md5 test.sh
openssl md5 /dev/null
echo -n "test.sh" > string ; openssl md5 string ; rm string
echo -n "" | openssl sha256
echo -n "hello" | openssl sha256
echo -n " " | openssl sha256
cat main.c | openssl sha256
openssl sha256 test.sh
openssl sha256 /dev/null
echo -n "test.sh" > string ; openssl sha256 string ; rm string
echo "\nnow ft_ssl:"
echo -n "" | ./ft_ssl md5
echo -n "hello" | ./ft_ssl md5
echo -n " " | ./ft_ssl md5
cat main.c | ./ft_ssl md5
./ft_ssl md5 test.sh
./ft_ssl md5 /dev/null
./ft_ssl md5 -s "test.sh"
echo -n "" | ./ft_ssl sha256
echo -n "hello" | ./ft_ssl sha256
echo -n " " | ./ft_ssl sha256
cat main.c | ./ft_ssl sha256
./ft_ssl sha256 test.sh
./ft_ssl sha256 /dev/null
./ft_ssl sha256 -s "test.sh"
echo "\nnow ft_ssl with vg:"
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh"
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh"
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -q
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -q -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -q
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -q -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -q
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -q -r
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -q
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -r
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -q -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -q
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -q -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -q
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -q -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" -q
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" -r
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh"  -q -r
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -q -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -q -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -q -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -q -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -q -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -q -r -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r -h
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -h
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r -h
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r -h
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -h
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r -h
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r -h
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -q -h
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -r -h
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -q -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -q -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -q -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -q -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -q -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" -q -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" -r -h
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh"  -q -r -h
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -q hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -q -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -q hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -q -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -q hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -q -r hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -q hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -r hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -q -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -q hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -q -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -q hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -q -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" -q hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" -r hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh"  -q -r hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -h hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -r -h hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -q -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -q -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 test.sh -q -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -q -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 /dev/null -q -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -q -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl md5 -s "test.sh" -q -r -h hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -h hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r -h hgfhdfhsg
echo -n "" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r -h hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -h hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r -h hgfhdfhsg
echo -n "hello" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r -h hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -h hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -r -h hgfhdfhsg
echo -n " " | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -q -r -h hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -q -h hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -r -h hgfhdfhsg
cat main.c | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./ft_ssl sha256 -q -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -q -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 test.sh -q -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -q -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 /dev/null -q -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" -q -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh" -r -h hgfhdfhsg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_ssl sha256 -s "test.sh"  -q -r -h hgfhdfhsg