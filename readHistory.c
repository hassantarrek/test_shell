#include "main.h"

/**
 * readHistory - reads history from file
 * @info: parameter
 * Return: 0 or history count
 */

int readHistory(info_h *info)
{
	int x, last = 0, lineCount = 0;
	ssize_t fd, len, size = 0;
	struct stat st;
	char *buff = NULL, *fileName = getHistoryFile(info);

	if (!fileName)
		return (0);
	fd = open(filename, O_RDONLY);
	free(fileName);
	if (fd == -1)
		return (0);
	if (!stat(fd, &st))
	{
		size = st.st_size;
	}
	if (size < 2)
		return (0);
	buff = malloc(sizeof(char) * (size + 1));
	if (!buff)
		return (0);
	len = read(fd, buff, size);
	buff[size] = 0;
	if (len <= 0)
		return (free(buff), 0);
	close(fd);
	for (x = 0; x < size; x++)
		if (buf[x] == '\n')
		{
			buff[x] = 0;
			buildHistoryList(info, buff + last, lineCount++);
			last = i + 1;
		}
	if (last != i)
		buildHistoryList(info, buff + last, lineCount++);
	free(buf);
	info->histCount = lineCount;
	while (info->histCount-- >= HIST_MAX)
		deleteNodeAtIndex(&(info->history), 0);
	renumberHistory(info);
	return (info->histCount);
}
