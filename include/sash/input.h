#ifndef INPUT_H_2C6A9CFE_83FE_4419_BEFD_E4B888681E1D
#define INPUT_H_2C6A9CFE_83FE_4419_BEFD_E4B888681E1D

struct command;

/**
 * @brief read_line Reads a line from stdin
 * @return char array containing line read
 */
char *read_line(void);

/**
 * @brief parse_line Parses a line read from stdin
 * @param input char array containing text to parse
 * @return array of inputs split by whitespace
 */
struct command *parse_line(char *input);

#endif // INPUT_H_2C6A9CFE_83FE_4419_BEFD_E4B888681E1D
