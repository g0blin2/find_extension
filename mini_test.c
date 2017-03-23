#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}

int	my_strlen(char *s)
{
  int	i;

  if (!s)
    return (0);
  i = 0;
  while (s[i])
    i++;
  return (i);
}

char    *my_strcat(char *stock1, char *stock2)
{
  char  *result;
  char  *copy;

  result = malloc(my_strlen(stock1) + my_strlen(stock2) + 1);
  copy = result;
  while (*stock1)
    *copy++ = *stock1++;
  while (*stock2)
    *copy++ = *stock2++;
  *copy = 0;
  return (result);
}

int		is_file(char *path)
{
  struct stat	params;

  if (stat(path, &params) == -1)
    perror("stat");
  free(path);
  return (params.st_mode & S_IFREG ? 1 : 0);
}

int check_extension(char *filename, char *ext)
{
  char *s;

  if(!filename) return(0);
  s= strrchr(filename,'.');
  if (!s) return (0);
  if(!my_strcmp(s,ext))
    return(1);
  return(0);
}

int		ctn_file()
{
  struct dirent	*file;
  DIR		*dirp;
  int		ctn_file_text;

  ctn_file_text = 0;
  dirp = opendir("test");
  if (dirp == NULL)
    exit (84);
  while ((file = readdir(dirp)))
    {
      if (is_file(my_strcat("test/", file->d_name)) == 1
	  && check_extension(file->d_name, ".txt") == 1)
	      ctn_file_text += 1;
    }
  closedir(dirp);
  return (ctn_file_text);
}
  
int	main(int ac, char **av)
{
  printf("%d\n", ctn_file());
  return (0);
}
