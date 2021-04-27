echo -n "" | openssl md5
echo -n "hello" | openssl md5
echo -n " " | openssl md5
cat main.c | openssl md5
echo -n "" | openssl sha256
echo -n "hello" | openssl sha256
echo -n " " | openssl sha256
cat main.c | openssl sha256
echo "\nnow ft_ssl:"
echo -n "" | ./ft_ssl md5
echo -n "hello" | ./ft_ssl md5
echo -n " " | ./ft_ssl md5
cat main.c | ./ft_ssl md5
echo -n "" | ./ft_ssl sha256
echo -n "hello" | ./ft_ssl sha256
echo -n " " | ./ft_ssl sha256
cat main.c | ./ft_ssl sha256