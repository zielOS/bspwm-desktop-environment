void
distributetags(const Arg *arg)
{
	Client *c;
	unsigned int ui = 1;
	int i = 0;

	Monitor *origselmon = selmon;
	for (selmon = mons; selmon; selmon = selmon->next) {

	for (c = selmon->clients; c; c = c->next) {
		if (HIDDEN(c))
			continue;
		if (!(c->tags & TAGMASK))
			continue;
		c->tags = (ui << i) & TAGMASK;
		i = (i + 1) % NUMTAGS;
	}

	}
	selmon = origselmon;
	arrange(NULL);
	focus(NULL);
}
