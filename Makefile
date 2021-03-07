NAME = index.html

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/
LIBRARIES = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="['png']"
SKELE_HTML = --shell-file srcs/skeleton.html

PRELOAD_FILES =							\
	resources/


PRELOAD = --preload-file $(PRELOAD_FILES)

all: $(NAME)

SDLX_DIR = SDLX/
SDLX_NAMES = 			\
	SDLX_init			\

FILE_NAMES =			\
	$(addprefix $(SDLX_DIR), $(SDLX_NAMES))		\
	moveset/moveset_bishop	\
	moveset/moveset_horse	\
	moveset/moveset_king	\
	moveset/moveset_pawn	\
	moveset/moveset_queen	\
	moveset/moveset_rook	\
	carve_chess_texture	\
	main				\
	render				\
	setup				\
	update_game_state	\
	user_interface		\
	utils				\

SRC_FILES = $(addsuffix .c, $(addprefix srcs/, $(FILE_NAMES)))

$(NAME):
	emcc $(FLAGS) $(INCLUDES) $(LIBRARIES) $(PRELOAD) $(SRC_FILES) $(SKELE_HTML) -o $(NAME)
	# open http://localhost:8000/cweb.html

fclean:
	rm -rf $(NAME)

re: fclean
	make all