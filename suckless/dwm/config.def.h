/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;   
static const int corner_radius      = 12;
static const unsigned int snap      = 32;  
static const int swallowfloating    = 0;   
static const unsigned int gappih    = 12; 
static const unsigned int gappiv    = 12;  
static const unsigned int gappoh    = 12;  
static const unsigned int gappov    = 12;  
static const int smartgaps_fact     = 1;   
static const int showbar            = 1;   
static const int topbar             = 0;   
static const int bar_height         = 27;   
static const int vertpad            = 5;  
static const int sidepad            = 5;

#define ICONSIZE    20    
#define ICONSPACING 5  

static const int statusmon              = -1;
static const int horizpadbar            = 2;   
static const int vertpadbar             = 0;   
static const char buttonbar[]           = "<O>";
static const unsigned int ulinepad      = 5;         
static const unsigned int ulinestroke   = 2;     
static const unsigned int ulinevoffset  = 0;     
static const int ulineall               = 0;               

static int tagindicatortype   = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype = INDICATOR_NONE;
static int floatindicatortype = INDICATOR_TOP_LEFT_SQUARE;

static const char *fonts[]    = { 
  "JetBrainsMono Nerd Font:size=12"};
static const char dmenufont[] = "monospace:size=10";



static char c000000[]              = "#000000"; // placeholder value

static char normfgcolor[]          = "#bbbbbb";
static char normbgcolor[]          = "#222222";
static char normbordercolor[]      = "#444444";
static char normfloatcolor[]       = "#db8fd9";

static char selfgcolor[]           = "#eeeeee";
static char selbgcolor[]           = "#005577";
static char selbordercolor[]       = "#005577";
static char selfloatcolor[]        = "#005577";

static char titlenormfgcolor[]     = "#bbbbbb";
static char titlenormbgcolor[]     = "#222222";
static char titlenormbordercolor[] = "#444444";
static char titlenormfloatcolor[]  = "#db8fd9";

static char titleselfgcolor[]      = "#eeeeee";
static char titleselbgcolor[]      = "#005577";
static char titleselbordercolor[]  = "#005577";
static char titleselfloatcolor[]   = "#005577";

static char tagsnormfgcolor[]      = "#bbbbbb";
static char tagsnormbgcolor[]      = "#222222";
static char tagsnormbordercolor[]  = "#444444";
static char tagsnormfloatcolor[]   = "#db8fd9";

static char tagsselfgcolor[]       = "#eeeeee";
static char tagsselbgcolor[]       = "#005577";
static char tagsselbordercolor[]   = "#005577";
static char tagsselfloatcolor[]    = "#005577";

static char hidnormfgcolor[]       = "#005577";
static char hidselfgcolor[]        = "#227799";
static char hidnormbgcolor[]       = "#222222";
static char hidselbgcolor[]        = "#222222";

static char urgfgcolor[]           = "#bbbbbb";
static char urgbgcolor[]           = "#222222";
static char urgbordercolor[]       = "#ff0000";
static char urgfloatcolor[]        = "#db8fd9";

static char *colors[][ColCount] = {
	/*                    fg                bg                border                float */
	[SchemeNorm]      = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]       = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm] = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]  = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]  = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]   = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]   = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]    = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]       = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};




const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spranger", "-g", "120x34", NULL };
const char *spcmd3[] = {"st", "-n", "splvim", "-g", "120x34", NULL };
const char *spcmd4[] = {"st", "-n", "spvifm", "-g", "120x34", NULL };

static Sp scratchpads[] = {
  {"spterm",   spcmd1},
  {"spranger", spcmd1},
  {"splvim",   spcmd1},
  {"spvifm",   spcmd1},
};

static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]  = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
};
static const Rule rules[] = {
  RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
  RULE(.instance = "spranger", .tags = SPTAG(1), .isfloating = 1)
  RULE(.instance = "splvim", .tags = SPTAG(2), .isfloating = 1)
  RULE(.instance = "spvifm", .tags = SPTAG(3), .isfloating = 1)
};

static const MonitorRule monrules[] = {
	/* mon.  lay  mfact  nmaster  showbar  topbar */
	{   1,    2,   -1,    -1,      -1,      -1     }, 
	{  -1,    0,   -1,    -1,      -1,      -1     },
  {  -1,    0,   -1,    -1,      -1,      -1     },
};

static const BarRule barrules[] = {
	/* monitor   bar alignment        widthfunc           drawfunc           clickfunc         hover name */
	{ -1,        0,  BAR_ALIGN_LEFT,  width_stbutton,     draw_stbutton,     click_stbutton,   NULL, "statusbutton" },
	{ -1,        0,  BAR_ALIGN_LEFT,  width_ltsymbol,     draw_ltsymbol,     click_ltsymbol,   NULL, "layout" },
	{ statusmon, 0,  BAR_ALIGN_RIGHT, width_statuscolors, draw_statuscolors, click_statuscmd,  NULL, "statuscolors" },
};

/* layout(s) */
static const float mfact        = 0.55; 
static const int nmaster        = 1;    
static const int resizehints    = 0;    
static const int lockfullscreen = 1; 

#define FORCE_VSPLIT 1

static const Layout layouts[] = {
	/* symbol  arrange function */
	{ "(@)",   spiral },
	{ "[]=",   tile },  
  { "TTT",   bstack },
	{ "===",   bstackhoriz },
	{ "|M|",   centeredmaster },
	{ ">M>",   centeredfloatingmaster },
	{ "|||",   col },
	{ "[D]",   deck },
	{ "[\\]",  dwindle },
	{ "HHH",   grid },
	{ "---",   horizgrid },
	{ "###",   nrowgrid },
  { "><>",   NULL }, 
};

/* key definitions */
#define MOD Mod4Mask
#define ALT Mod1Mask
#define CTRL ControlMask
#define SHIFT ShiftMask

#define TAGKEYS(KEY,TAG) \
  { MOD,            KEY,  view,        {.ui = 1 << TAG} }, \
	{ MOD|CTRL,       KEY,  toggleview,  {.ui = 1 << TAG} }, \
	{ MOD|SHIFT,      KEY,  tag,         {.ui = 1 << TAG} }, \
	{ MOD|CTRL|SHIFT, KEY,  toggletag,   {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *btncmd[]  = { "dwmmenu", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MOD,                       XK_b,          togglebar,              {0} },
	{ MOD,                       XK_j,          focusstack,             {.i = +1 } },
	{ MOD,                       XK_k,          focusstack,             {.i = -1 } },
	{ MOD,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MOD,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MOD,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MOD,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MOD|SHIFT,             XK_h,          setcfact,               {.f = +0.25} },
	{ MOD|SHIFT,             XK_l,          setcfact,               {.f = -0.25} },
	{ MOD|SHIFT,             XK_o,          setcfact,               {0} },
	{ MOD|SHIFT,             XK_j,          movestack,              {.i = +1 } },
	{ MOD|SHIFT,             XK_k,          movestack,              {.i = -1 } },
	{ MOD|CTRL,           XK_d,          distributetags,         {0} },
	{ MOD,                       XK_Return,     zoom,                   {0} },
	{ MOD,                       XK_Tab,        view,                   {0} },
	{ MOD|SHIFT,             XK_Left,       shifttag,               { .i = -1 } }, 
	{ MOD|SHIFT,             XK_Right,      shifttag,               { .i = +1 } }, 
	{ MOD|SHIFT|CTRL, XK_Left,       shifttagclients,        { .i = -1 } },
	{ MOD|SHIFT|CTRL, XK_Right,      shifttagclients,        { .i = +1 } },
	{ MOD|SHIFT,             XK_Tab,        shiftview,              { .i = -1 } },
	{ MOD|SHIFT,             XK_backslash,  shiftview,              { .i = +1 } },
	{ MOD|Mod4Mask,              XK_Tab,        shiftviewclients,       { .i = -1 } },
	{ MOD|Mod4Mask,              XK_backslash,  shiftviewclients,       { .i = +1 } },
	{ MOD|CTRL,           XK_Left,       shiftboth,              { .i = -1 } }, 
	{ MOD|CTRL,           XK_Right,      shiftboth,              { .i = +1 } }, 
	{ MOD,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MOD,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MOD,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MOD,                       XK_c,          setlayout,              {.v = &layouts[3]} },
	{ MOD,                       XK_space,      setlayout,              {0} },
	{ MOD|SHIFT,             XK_space,      togglefloating,         {0} },
	{ MOD,                       XK_grave,      togglescratch,          {.ui = 0 } },
	{ MOD|CTRL,           XK_grave,      setscratch,             {.ui = 0 } },
	{ MOD|SHIFT,             XK_grave,      removescratch,          {.ui = 0 } },
	{ MOD,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MOD,                       XK_period,     focusmon,               {.i = +1 } },
	{ MOD|SHIFT,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MOD|SHIFT,             XK_period,     tagmon,                 {.i = +1 } },
	{ MOD|CTRL,           XK_comma,      cyclelayout,            {.i = -1 } },
	{ MOD|CTRL,           XK_period,     cyclelayout,            {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)	
  TAGKEYS(                        XK_2,                                  1)	
  TAGKEYS(                        XK_3,                                  2)
  TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkButton,            0,                   Button1,        spawn,          {.v = btncmd } },
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static const Signal signals[] = {
	/* signum                    function */
	{ "focusstack",              focusstack },
	{ "setmfact",                setmfact },
	{ "togglebar",               togglebar },
	{ "incnmaster",              incnmaster },
	{ "togglefloating",          togglefloating },
	{ "focusmon",                focusmon },
	{ "setcfact",                setcfact },
	{ "tagmon",                  tagmon },
	{ "zoom",                    zoom },
	{ "incrgaps",                incrgaps },
	{ "incrigaps",               incrigaps },
	{ "incrogaps",               incrogaps },
	{ "incrihgaps",              incrihgaps },
	{ "incrivgaps",              incrivgaps },
	{ "incrohgaps",              incrohgaps },
	{ "incrovgaps",              incrovgaps },
	{ "togglegaps",              togglegaps },
	{ "defaultgaps",             defaultgaps },
	{ "setgaps",                 setgapsex },
	{ "view",                    view },
	{ "viewall",                 viewallex },
	{ "viewex",                  viewex },
	{ "toggleview",              toggleview },
	{ "shiftboth",               shiftboth },
	{ "shifttag",                shifttag },
	{ "shifttagclients",         shifttagclients },
	{ "shiftview",               shiftview },
	{ "shiftviewclients",        shiftviewclients },
	{ "cyclelayout",             cyclelayout },
	{ "toggleviewex",            toggleviewex },
	{ "tag",                     tag },
	{ "tagall",                  tagallex },
	{ "tagex",                   tagex },
	{ "toggletag",               toggletag },
	{ "toggletagex",             toggletagex },
	{ "togglescratch",           togglescratch },
	{ "killclient",              killclient },
	{ "quit",                    quit },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
};

