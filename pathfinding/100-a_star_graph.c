#include <math.h>
#include <stdlib.h>
#include "pathfinding.h"

#define EUCLIDEAN_DISTANCE(a, b) \
	(sqrt(pow((b)->x - (a)->x, 2) + pow((b)->y - (a)->y, 2)))

/* STATIC FUNCTIONS */

static const vertex_t *pq_insert(astar_ctx_t *ctx, const vertex_t *vertex);

static const vertex_t *pq_extract(astar_ctx_t *ctx);

static astar_ctx_t *astar_ctx_create(graph_t *graph, const vertex_t *start,
	const vertex_t *target);

/* API IMPLEMENTATION */

queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	;
}

/* STATIC FUNCTIONS */

static astar_ctx_t *astar_ctx_create(graph_t *graph, const vertex_t *start,
	const vertex_t *target)
{
	;
}

/*

static dijkstra_ctx_t *dijkstra_ctx_create(graph_t *graph,
	const vertex_t *start, const vertex_t *target)
{
	dijkstra_ctx_t *ctx = NULL;
	queue_t *path = NULL;
	size_t alloc_size, i;

	path = queue_create();

	if (!path)
		return (NULL);

	alloc_size = sizeof(dijkstra_ctx_t);
	alloc_size += graph->nb_vertices * sizeof(dijkstra_entry_t);
	alloc_size += graph->nb_vertices * sizeof(const vertex_t *);
	ctx = calloc(1, alloc_size);

	if (!ctx)
	{
		queue_delete(path);
		return (NULL);
	}

	ctx->graph = graph;
	ctx->entries = (dijkstra_entry_t *)(ctx + 1);

	for (i = 0; i < graph->nb_vertices; ++i)
		ctx->entries[i].distance = INFINITY;

	ctx->entries[start->index].distance = 0L;
	ctx->pq = (const vertex_t **)(ctx->entries + graph->nb_vertices);
	ctx->start = start;
	ctx->target = target;
	ctx->path = path;
	return (ctx);
}

static const vertex_t *pq_insert(dijkstra_ctx_t *ctx, const vertex_t *vertex)
{
	const vertex_t *pos = NULL, *parent = NULL, *tmp = NULL;
	size_t i, j;

	if (ctx->pq_size == ctx->graph->nb_vertices)
		return (NULL);

	i = ctx->pq_size++;
	ctx->pq[i] = vertex;

	while (i > 0)
	{
		j = HEAP_PARENT(i);
		pos = ctx->pq[i];
		parent = ctx->pq[j];

		if (DISTANCE(ctx, parent) <= DISTANCE(ctx, pos))
			break;

		tmp = ctx->pq[i];
		ctx->pq[i] = ctx->pq[j];
		ctx->pq[j] = tmp;

		i = j;
	}

	FRONTIER(ctx, vertex) = 1;
	return (vertex);
}


static const vertex_t *pq_extract(dijkstra_ctx_t *ctx)
{
	const vertex_t *root = NULL, *tmp1 = NULL, *tmp2 = NULL;
	size_t i, j;

	if (!ctx->pq_size)
		return (NULL);

	root = ctx->pq[0];
	ctx->pq[0] = ctx->pq[--ctx->pq_size];

	for (i = 0; HEAP_LEFT(i) < ctx->pq_size; i = j)
	{
		if (HEAP_RIGHT(i) < ctx->pq_size)
		{
			tmp1 = ctx->pq[HEAP_LEFT(i)];
			tmp2 = ctx->pq[HEAP_RIGHT(i)];
			j = (DISTANCE(ctx, tmp1) <= DISTANCE(ctx, tmp2))
				? HEAP_LEFT(i)
				: HEAP_RIGHT(i);
		}
		else
		{
			j = HEAP_LEFT(i);
		}

		tmp1 = ctx->pq[i];
		tmp2 = ctx->pq[j];

		if (DISTANCE(ctx, tmp1) <= DISTANCE(ctx, tmp2))
			break;

		tmp1 = ctx->pq[i];
		ctx->pq[i] = ctx->pq[j];
		ctx->pq[j] = tmp1;
	}

	FRONTIER(ctx, root) = 0;
	return (root);
}



*/