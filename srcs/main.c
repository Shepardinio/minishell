#include "../include/minishell.h"

#include <stdio.h>
t_nns *nns_init(char *input)
{
	t_nns *nns;

	nns = malloc(sizeof(t_nns));
	if (nns == NULL)
		return NULL;
	nns->name = NULL;
	nns->newstr = ft_strdup(input);
	if (!nns->newstr)
		return NULL;
	return nns;
}

t_pipeline *pipeline_init()
{
	t_pipeline *pipeline;
	pipeline = malloc(sizeof(t_pipeline));
	if (pipeline == NULL)
		return NULL;
	pipeline->cmd = NULL;
	pipeline->infiles = NULL;
	pipeline->outfiles = NULL;
	pipeline->outfiles_ext = NULL;
	pipeline->here_docs = NULL;
	pipeline->infile_fd = 0;
	pipeline->outfile_fd = 1;
	// ft_memset(pipeline, 0, sizeof(t_pipeline));
	// *pipeline = (t_pipeline){0};
	return pipeline;
}

char *two_signs_handler(char *input)
{
	int i;
	char *new_input;

	if (input[0] == '\0')
		return NULL;
	new_input = ft_strdup(input);
	if (new_input == NULL)
		return NULL;
	i = 0;
	while (new_input[i+1])
	{
		if (new_input[i] == '<' && new_input[i+1] == '<')
		{
			new_input[i] = -1;
			new_input[i+1] = ' ';
		}else if (new_input[i] == '>' && new_input[i+1] == '>')
		{
			new_input[i] = -2;
			new_input[i+1] = ' ';
		}
		i++;
	}
	return (new_input);
}

void error_exit()
{
	exit(-1);
}

void free_pipeline(t_pipeline *pipeline)
{
	int i;

	i = 0;
	while(pipeline->cmd[i])
		free(pipeline->cmd[i++]);
	free(pipeline->cmd);
	i = 0;
	while (pipeline->infiles[i])
		free(pipeline->infiles[i++]);
	free(pipeline->infiles);
	i = 0;
	while (pipeline->outfiles[i])
		free(pipeline->outfiles[i++]);
	free(pipeline->outfiles);
	i = 0;
	while (pipeline->outfiles_ext[i])
		free(pipeline->outfiles_ext[i++]);
	free(pipeline->outfiles_ext);
	i = 0;
	while (pipeline->here_docs[i])
		free(pipeline->here_docs[i++]);
	free(pipeline->here_docs);
	free(pipeline);
}

void free_all_pipelines(t_all_pipelines *all_pipelines)
{
	int i;

	i = 0;
	if (!all_pipelines)
		return ;
	if (!all_pipelines->pipelines)
		return ;
	while (all_pipelines->pipelines[i] != NULL)
	{
			free_pipeline(all_pipelines->pipelines[i]);
			i++;
	}
	free(all_pipelines->pipelines);
	free(all_pipelines);
}

void print_array(char **array, const char *name)
{
    printf("%s: {", name);
    if (array != NULL)
    {
        for (int i = 0; array[i] != NULL; ++i)
        {
            printf("\"%s\"", array[i]);
            if (array[i + 1] != NULL)
                printf(", ");
        }
    }
    printf("}\n");
}

// Fonction pour afficher le contenu de t_pipeline
void print_pipeline(const t_pipeline *pipeline)
{
    if (pipeline == NULL)
    {
        printf("Pipeline is NULL\n");
        return;
    }

    printf("Command: {");
    if (pipeline->cmd != NULL)
    {
        for (int i = 0; pipeline->cmd[i] != NULL; ++i)
        {
            printf("\"%s\"", pipeline->cmd[i]);
            if (pipeline->cmd[i + 1] != NULL)
                printf(", ");
        }
    }
    printf("}\n");

    print_array(pipeline->infiles, "Infiles");
    print_array(pipeline->outfiles, "Outfiles");
    print_array(pipeline->outfiles_ext, "Outfiles Ext");
    print_array(pipeline->here_docs, "Here Docs");
}

// Fonction pour afficher le contenu de t_all_pipelines
void print_all_pipelines(const t_all_pipelines *all_pipes)
{
    if (all_pipes == NULL)
    {
        printf("All Pipelines is NULL\n");
        return;
    }

    printf("Pipelines:\n");
    if (all_pipes->pipelines != NULL)
    {
        for (int i = 0; all_pipes->pipelines[i] != NULL; ++i)
        {
            printf("Pipeline %d:\n", i);
            print_pipeline(all_pipes->pipelines[i]);
            printf("\n");
        }
    }
    else
    {
        printf("No pipelines found.\n");
    }
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_data data;

	init_data(&data, env);
	// while (1)
	// {
		ft_putstr_fd("Minishell> ", 1);
		char *test = "< Makefile cat | wc -l | wc -c | wc";
		// char *test = get_next_line(0);
		// *ft_strchr(test, '\n') = '\0';
		char *input = two_signs_handler(test);
		if (input == NULL)
			error_exit();
		data.all_pipes = pipelines_creator(input);
		free(input);
		// printf("%s\n",data.all_pipes->pipelines[4]->cmd[1]);
		print_all_pipelines(data.all_pipes);
		execution(&data);
		free_all_pipelines(data.all_pipes);
	// }
	// execution(&data);
	free_all(&data);
	return (0);
}
