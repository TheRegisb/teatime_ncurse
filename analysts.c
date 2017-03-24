/*
** analysts.c for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Thu Mar 23 18:37:33 2017 Régis Berthelot
** Last update Thu Mar 23 18:37:39 2017 Régis Berthelot
*/

int	get_time_option(char *str)
{
  int	i;
  int	res;

  i = 0;
  while (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (-1);
  res = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (-1);
      res = (res * 10) + (str[i] - 48);
      i++;
    }
  return (res);
}

int	is_numeric(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      i++;
    }
  return (1);
}
