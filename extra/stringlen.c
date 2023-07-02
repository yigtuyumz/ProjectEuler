unsigned long int stringlen(const char *s)
{
	unsigned long int len = 0;
	while (*(s + len++)) ;
	return (--len);
}
