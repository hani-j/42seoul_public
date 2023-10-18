/* ----------------------t_parser_flag----------------------- */

typedef enum e_parser_flag
{
	PARSER_INIT = 1 << 0,
	PARSER_FINISH = 1 << 1,
}	t_parser_flag;


/* ----------------------t_heredoc_list----------------------- */

typedef struct s_heredoc_list
{
	t_redir_list	*redir_list;
}	t_heredoc_list;


/* ----------------------t_value_stack----------------------- */

typedef struct s_element
{
	char			*word;
	t_redir_list	*redir_list;
}	t_element;

typedef struct s_word_list
{
	int			flag;
	int			key_len;
	int			field;
	char		*word;
	t_word_list	*variables;
}	t_word_list;
typedef struct s_simple
{
	int				flag;
	t_word_list		*words;
}	t_simple;
typedef struct s_connect
{
	t_symbol_type	tok;
	t_cmd			*left;
	t_cmd			*right;
}	t_connect;
typedef struct s_subshell
{
	int		flag;
	t_cmd	*cmd;
}	t_subshell;
typedef union u_cmd_content
{
	t_simple	simple;
	t_connect	connect;
	t_subshell	subshell;
}	t_cmd_content;
typedef enum e_cmd_type
{
	CMD_SIMPLE,
	CMD_CONNECT,
	CMD_SUBSHELL
}	t_cmd_type;
typedef enum e_cmd_flag
{
	CMD_FLAG_DEFAULT = 0,
	CMD_FLAG_NEED_FORK = 1 << 0,
	CMD_FLAG_IS_FORKED = 1 << 1,
	CMD_FLAG_NEED_PIPE = 1 << 2
}	t_cmd_flag;
typedef struct s_cmd
{
	t_cmd_flag		flag;			// fork 여부 pipe 여부 판단
	t_cmd_type		type;			// simple / connect / subshell
	t_redir_list	*redir_list;	// 
	t_cmd_content	content;		// 
	t_env_list		*env;			// 환경변수
	pid_t			pid_last_child;	// 마지막 자식 pid 값
	int				exit_status;	// 종료 확인 (?)
}	t_cmd;

typedef enum e_redir_type
{
	REDIR_NON,
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND
}	t_redir_type;
typedef struct s_redir_list
{
	t_redir_type	redir_type;		// < , > , << , >>
	int				flag;			//
	int				fd_orig;		// 바꾸기 전 fd
	int				fd_new;			// 바꿀 fd
	char			*filename;		// file 이름
	char			*heredoc_eof;	// heredoc 문자열 (?)
}	t_redir_list;

typedef union u_value_content
{
	t_symbol_type	token;
	char			*word;
	t_redir_list	*redir_list;
	t_cmd			*cmd;
	t_element		*element;
}	t_value_content;

typedef enum e_value_type
{
	VALUE_TOKEN,
	VALUE_WORD,
	VALUE_REDIR_LIST,
	VALUE_ELEMENT,
	VALUE_CMD
}	t_value_type;

typedef struct s_value_stack
{
	t_value_type	type;			// token / word / redir_list / cmd / element
	t_value_content	content;
}	t_value_stack;


/* ----------------------t_parser_stack----------------------- */

typedef enum e_parser_state
{
	STATE_NON = 0,
	PARSER_STATE = 1 << 20,
	STATE_0 = PARSER_STATE | 0,
	STATE_1 = PARSER_STATE | 1,
	STATE_2 = PARSER_STATE | 2,
	STATE_3 = PARSER_STATE | 3,
	STATE_4 = PARSER_STATE | 4,
	STATE_5 = PARSER_STATE | 5,
	STATE_6 = PARSER_STATE | 6,
	STATE_7 = PARSER_STATE | 7,
	STATE_8 = PARSER_STATE | 8,
	STATE_9 = PARSER_STATE | 9,
	STATE_10 = PARSER_STATE | 10,
	STATE_11 = PARSER_STATE | 11,
	STATE_12 = PARSER_STATE | 12,
	STATE_13 = PARSER_STATE | 13,
	STATE_14 = PARSER_STATE | 14,
	STATE_15 = PARSER_STATE | 15,
	STATE_16 = PARSER_STATE | 16,
	STATE_17 = PARSER_STATE | 17,
	STATE_18 = PARSER_STATE | 18,
	STATE_19 = PARSER_STATE | 19,
	STATE_20 = PARSER_STATE | 20,
	STATE_21 = PARSER_STATE | 21
}	t_parser_state;

typedef union u_stack_content
{
	t_parser_state	state;			// state
	t_symbol_type	symbol;			// TT
}	t_stack_content;

typedef struct s_parser_stack
{
	int				type;			// PARSER_STATE or 0 
	t_stack_content	content;		// state 		or TT
}	t_parser_stack;


/* ----------------------input----------------------- */

typedef enum e_symbol_type
{
	SYMBOL_ERR = 0,
	SYMBOL_WORD = 1,
	SYMBOL_PAREN_LEFT = 1 << 1,
	SYMBOL_PAREN_RIGHT = 1 << 2,
	SYMBOL_PIPE = 1 << 3,
	SYMBOL_OR = 1 << 4,
	SYMBOL_AND = 1 << 5,
	SYMBOL_REDIR_IN = 1 << 6,
	SYMBOL_REDIR_OUT = 1 << 7,
	SYMBOL_REDIR_HEREDOC = 1 << 8,
	SYMBOL_REDIR_APPEND = 1 << 9,
	SYMBOL_EOF = 1 << 10,
	SYMBOL_START = 1 << 11,
	SYMBOL_LIST = 1 << 12,
	SYMBOL_PIPELINE = 1 << 13,
	SYMBOL_CMD = 1 << 14,
	SYMBOL_SIMPLE = 1 << 15,
	SYMBOL_SUBSHELL = 1 << 16,
	SYMBOL_REDIR_LIST = 1 << 17,
	SYMBOL_ELEMENT = 1 << 18,
	SYMBOL_REDIR = 1 << 19
}	t_symbol_type;

typedef struct s_token
{
	t_symbol_type	type;			// TT
	char			*content;		// token 문자열
}	t_token;

/* ----------------------t_parser----------------------- */

typedef struct s_parser
{
	t_token			*input; 		// TT와 token 문자열 하나 저장
	t_parser_stack	*parser_stack;	// type(?) 과 state or TT 저장
	t_value_stack	*value_stack;	// TT / word / redir_list / element / cmd type 과 그 중 하나 저장
	t_heredoc_list	*heredoc_list;	// redir_list 와 같음
	t_parser_flag	flag;			// init -> finish 될 때까지 파싱
	t_cmd			*final_cmd;		// 마지막 cmd
}	t_parser;



0	S -> L				// parser->final_cmd -> cmd
1	L -> L && P			// connect -> cmd
2	L -> P				// cmd -> cmd
3	P -> P | C			// connect -> cmd 
4	P -> C				// cmd -> cmd
5	C -> SC				// cmd -> simple
6	C -> SUB			// cmd -> subshell
7	C -> SUB RL			// cmd && cmd -> subshell redir_list
8	SC -> SC ELEM		// simple -> element
9	SC -> ELEM			// simple -> element
10	SUB -> ( L )		// subshell -> cmd
11	RL -> RL R			// redir_list -> redir_list
12	RL -> R				// redir_list -> redir_list
13	ELEM -> id			// element -> word
14	ELEM -> R 			// element -> redir_list
15	R -> > id			// redir_list or heredoc -> id