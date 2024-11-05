#include "../include/minishell.h"

void write_signals(bool write_signal)
{
    struct termios termios_p;

    if (tcgetattr(STDIN_FILENO, &termios_p) != 0)
    {
        perror("tcgetattr");
        return;
    }

    if (write_signal == false)
        termios_p.c_lflag &= ~ECHOCTL; // Oculta ^C, ^D
    else
        termios_p.c_lflag |= ECHOCTL;  // Muestra ^C, ^D

    if (tcsetattr(STDIN_FILENO, TCSANOW, &termios_p) != 0)
        perror("tcsetattr");
}
