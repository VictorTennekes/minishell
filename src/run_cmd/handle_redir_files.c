#include <minishell.h>
#include <fcntl.h>
#include <unistd.h>

int	g_redir_oflags[] = {
	[WRITE] = O_WRONLY | O_CREAT,
	[APPEND] = O_APPEND,
	[INPUT] = O_RDONLY,
};

static void	handle_redir(t_mshell *mshell, t_redir_file redir,
		t_cmd_directions *directions)
{
	int	fd;
	int	mode;

	mode = 0;
	if (redir.redir_type == WRITE || redir.redir_type == APPEND)
		mode = 0644;
	fd = open(redir.redir_filename.str, g_redir_oflags[redir.redir_type], mode);
	if (fd == -1)
		error("failed to open file", mshell);
	if (directions->has_redirect[redir.redir_type])
		close(directions->redirect_fd[redir.redir_type]);
	directions->has_redirect[redir.redir_type] = true;
	directions->redirect_fd[redir.redir_type] = fd;
}

void	handle_redir_files(t_mshell *mshell, t_redir_file *redir_files,
		size_t redir_count, t_cmd_directions *directions)
{
	size_t				i;

	i = 0;
	while (i < redir_count)
	{
		handle_redir(mshell, redir_files[i], directions);
		i++;
	}
}

