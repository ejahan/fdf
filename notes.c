nombre de lignes
recup dans un tableau



int tableau[5]
int *tableau

int tab[][]
int (*tab)[]
int **tab?



http://mdevmd.accesmad.org/mediatek/mod/page/view.php?id=1580
https://www.techno-science.net/definition/5558.html
https://fr.wikipedia.org/wiki/Perspective_isom%C3%A9trique










mettre en perspective isométrique avec tous les points au meme niveau (altitude == 0)
mettre les points avec altitude != 0 au bon endroit
	calculer max et min et apres jsp
relier les points entre eux avec des segments (équations de droite?)














int	iso(t_fdf *fdf, int l, int a) //>>>>>> l = screen_size / (line + column)
{
	// int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	fdf->x = l / 2 + fdf->line * a;
	fdf->y = l / 2;
	while (j < fdf->line)
	{
		x = fdf->x - j * a;
		find_p(fdf, x);
		while (i < fdf->column_max)
		{
			x = fdf->x + a * i;
			// printf("x = %d\n", x);
			// printf("y = %f\n", 0.82 * x + fdf->p);
			my_mlx_pixel_put(fdf, x, 0.82 * x + fdf->p_column, create_trgb(21, 255, 255, 255));
			i++;
		}
	}
	return (1);
}


// int	iso(t_fdf *fdf, int l, int a) //>>>>>> l = screen_size / (line + column)
// {
// 	// int	y;
// 	int	x;
// 	int	i;

// 	i = 0;
// 	fdf->x = l / 2 + fdf->line * a;
// 	fdf->y = l / 2;
// 	find_p(fdf);
// 	while (i < fdf->column_max)
// 	{
// 		x = fdf->x + a * i;
// 		printf("x = %d\n", x);
// 		// printf("x = %d\n", x);
// 		// printf("y = %f\n", 0.82 * x + fdf->p);
// 		my_mlx_pixel_put(fdf, x, 0.82 * x + fdf->p_column, create_trgb(21, 255, 255, 255));
// 		i++;
// 	}
// 	return (1);
// }




// int	screen_size(t_fdf *fdf, int l)  //>>>>>>> MARCHE PAS DU TOUT
// {
// 	int	y;
// 	int	x;
// 	int	i;

// 	fdf->m = (fdf->screen_size - l * (fdf->column_max - 1)) / 2;
// 	fdf->n = (fdf->screen_size - l * (fdf->line - 1)) / 2;
// 	y = l + fdf->n;
// 	x = (l + fdf->n - fdf->m) / -1.73;
// 	fdf->b = fdf->m - x;
// 	i = fdf->b * fdf->line;
// 	printf("m = %d\n", fdf->m);
// 	printf("x = %d\n", x);
// 	printf("b = %d\n", fdf->b);
// 	printf("i = %d\n", i);
// 	return (i);
// }


// int	put_isometric(t_fdf *fdf, int l)
// {
// 	int	i;
// 	int	j;
// 	int	m;
// 	int	n;

// 	i = 0;
// 	j = 0;
// 	m = (fdf->screen_size - l * (fdf->column_max - 1)) / 2;
// 	n = (fdf->screen_size - l * (fdf->line - 1)) / 2;
// 	while (i < fdf->line)
// 	{
// 		while (j < fdf->column_max)
// 		{
// 			fdf->color = create_trgb(21, 255, 255, 255);
// 			if (fdf->tab[i][j] != 0)
// 				fdf->color = create_trgb(21, 255, 0, 0);
// 			my_mlx_pixel_put(fdf, j * l + m + fdf->p, i * l + n,
// 				fdf->color);
// 			fdf->p = fdf->p - fdf->b;
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	return (1);
// }



// int	calculs(t_fdf *fdf, int l)
// {
// 	int	i;
// 	int	j;
// 	int	m;
// 	int	n;

// 	i = 0;
// 	j = 0;
// 	m = (fdf->screen_size - l * (fdf->column_max - 1)) / 2;
// 	n = (fdf->screen_size - l * (fdf->line - 1)) / 2;
// 	while (i < fdf->line)
// 	{
// 		while (j < fdf->column_max)
// 		{
// 			my_mlx_pixel_put(fdf, j * l + m, i * l + n,
// 				create_trgb(21, 255, 255, 255));
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	return (1);
// }



			fdf->color /= fdf->tab[j][i] * 2;










static int	recup_line_nbr(char **av, t_fdf *fdf)
{
	int		fd;
	char	*line;

	fdf->line = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line2(fd, &line) == 1)
	{
		fdf->line++;
		free(line);
	}
	free(line);
	if (get_next_line2(fd, &line) == -1)
	{
		close(fd);
		return (-1);
	}
	free(line);
	close(fd);
	return (1);
}

static void	recup_column_nbr(char *line, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ' && line[i] != '\0')
			j++;
		while (line[i] != '\0' && line[i] != ' ')
			i++;
	}
	fdf->column = j;
	if (fdf->column > fdf->column_max)
		fdf->column_max = fdf->column;
}

static int	fill_tab2(char *line, t_fdf *fdf, int n)
{
	static int	i = 0;
	int			j;
	char		*tmp;

	j = 0;
	recup_column_nbr(line, fdf);
	fdf->tab[i] = malloc(sizeof(int) * fdf->column);
	if (!(fdf->tab[i]))
		return (-1);
	while (j < fdf->column)
	{
		tmp = new_tmp(line, ft_strlen(line), n);
		n = 1;
		if (tmp == NULL)
			return (-1);
		fdf->tab[i][j] = ft_atoi(tmp);
		free(tmp);
		j++;
	}
	i++;
	return (1);
}

static int	fill_tab(char **av, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	i = get_next_line2(fd, &line);
	while (i == 1 || i == 0)
	{
		if (i == 0)
		{
			fill_tab2(line, fdf, 0);
			free(line);
			close(fd);
			return (1);
		}
		i = fill_tab2(line, fdf, 0);
		free(line);
		if (i == 1)
			i = get_next_line2(fd, &line);
	}
	close(fd);
	return (-1);
}

int	recup_map(char **av, t_fdf *fdf)
{
	int	i;

	i = recup_line_nbr(av, fdf);
	fdf->column_max = 0;
	if (i == -1)
		return (-1);
	fdf->tab = malloc(sizeof(int *) * fdf->line);
	if (!(fdf->tab))
		return (-1);
	i = fill_tab(av, fdf);
	if (i == -1)
		return (-1);
	return (1);
}











NAME		=	so_long

## Sources
INCS		=	-I incs -Llibft -lft -Ilibft/incs
MLIBX		=	libmlx.dylib

# Paths
PATH_SRCS	:=	./srcs

PATH_COMMON	:=	common
PATH_ENGINE	:=	engine
PATH_EVENTS	:=	events
PATH_PARSER	:=	parser

SRCS		=	$(PATH_SRCS)/$(PATH_COMMON)/free_all.c \
				$(PATH_SRCS)/$(PATH_COMMON)/utils.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/display.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/engine_loop.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/map.c \
				$(PATH_SRCS)/$(PATH_EVENTS)/handle_keys.c \
				$(PATH_SRCS)/$(PATH_EVENTS)/quit_events.c \
				$(PATH_SRCS)/$(PATH_PARSER)/parse_map.c \
				$(PATH_SRCS)/$(PATH_PARSER)/parser.c \
				$(PATH_SRCS)/main.c

OBJS		=	$(SRCS:.c=.o)

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f


.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I incs -Ilibft/incs -Imlx_linux


$(NAME):	$(OBJS)
			@echo "COMPILING ON $(YELLOW)Linux $(CLR_COLOR)...\n"
			@echo "[1/3] - Compiling $(CYAN)libft $(CLR_COLOR)..."
			@$(MAKE) -C libft all >/dev/null
			@echo "[2/3] - Compiling $(CYAN)mlx $(CLR_COLOR)..."
			@$(MAKE) -C mlx_linux all >/dev/null 2>&1
			@echo "[3/3] - Compiling $(RED)project $(CLR_COLOR)..."
			@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux $(OBJS) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(INCS) -o $(NAME)
endif


all:		$(NAME)


bonus:		$(OBJS)
			@echo "COMPILING BONUSES ON $(YELLOW)Linux $(CLR_COLOR)...\n"
			@echo "[1/3] - Compiling $(CYAN)libft $(CLR_COLOR)..."
			@$(MAKE) -C libft all >/dev/null
			@echo "[2/3] - Compiling $(CYAN)mlx $(CLR_COLOR)..."
			@$(MAKE) -C mlx_linux all >/dev/null 2>&1
			@echo "[3/3] - Compiling $(RED)project $(CLR_COLOR)..."
			@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -DBONUS $(SRCS) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(INCS) -o $(NAME)
endif


clean:
			@echo "Cleaning $(CYAN)Libft$(CLR_COLOR) objects ..."
			@$(MAKE) -C libft clean >/dev/null
			@echo "Cleaning $(CYAN)mlx$(CLR_COLOR) objects ..."
			@$(MAKE) -C mlx clean >/dev/null
			@$(MAKE) -C mlx_linux clean >/dev/null
			@$(RM) $(OBJS)


fclean:		clean
			@echo "Deleting $(CYAN)Libft$(CLR_COLOR) library ..."
			@$(MAKE) -C libft fclean >/dev/null
			@echo "Deleting $(CYAN)mlx$(CLR_COLOR) library ..."
			@$(RM) $(MLIBX)
			@echo "Deleting $(RED)$(NAME)$(CLR_COLOR) binary ..."
			@$(RM) $(NAME)


re:			fclean all


.PHONY:		all bonus clean fclean re









fdf->column		=	nombre colonnes
fdf->line		=	nombre lignes
fdf->p_column	=	p pour toute une meme ligne
fdf->p_line		=	p pour nouvelle ligne 
fdf->x 			=	premier x de premiere ligne
fdf->y			=	premier y de premiere ligne
fdf->altitude	=	valeur altitude en fonction de fdf->a
fdf->i			=	quelle colonne
fdf->j			=	quelle ligne
fdf->a			=	taille entre chaque x
fdf->max		=	altitude maximum
fdf->min		=	altitude minimum
x2				=	premier x (=debut) de chaques nouvelles lignes 
l 				=	espace restant entre fin rectangle & fin ecran

