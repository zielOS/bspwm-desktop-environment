static Arg
shift(const Arg *arg, int clients)
{
	Arg shifted;
	Client *c;
	unsigned int tagmask = 0;

	shifted.ui = selmon->tagset[selmon->seltags];

	Monitor *origselmon = selmon;
	for (selmon = mons; selmon; selmon = selmon->next)
	for (c = selmon->clients; c && clients; c = c->next) {
		if (c == selmon->sel)
			continue;
		if (!(c->tags & SPTAGMASK))
			tagmask |= c->tags;
	}
	selmon = origselmon;

	do {
		if (arg->i > 0) // left circular shift
			shifted.ui = (shifted.ui << arg->i) | (shifted.ui >> (NUMTAGS - arg->i));
		else // right circular shift
			shifted.ui = (shifted.ui >> -arg->i) | (shifted.ui << (NUMTAGS + arg->i));
		shifted.ui &= ~SPTAGMASK;
	} while (tagmask && !(shifted.ui & tagmask));

	return shifted;
}
