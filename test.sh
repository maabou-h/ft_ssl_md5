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
