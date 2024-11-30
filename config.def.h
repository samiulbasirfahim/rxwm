/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int scalepreview       = 4;        /* preview scaling (display w and h / scalepreview) */
static const int previewbar         = 0;        /* show the bar in the preview window */
static const int swallowfloating    = 1;        /* 1 means swallow floating windows by default */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 8;   /* systray spacing */
static const unsigned int systrayiconsize = 16; /* systray icon size in px */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int border_when_only   = 0;        /* 0 means no border for single tiled window */
static const int allowkill          = 1;        /* allow killing clients by default? */
static const char *fonts[]          = { 
    "IosevkaTermSlab Nerd Font:pixelsize=17:style=semibold",
};
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */ 
static const int horizpadbar        = 0;        /* horizontal padding for statusbar */
static const int vertpadbar         = 6;        /* vertical padding for statusbar */
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char normscrbordercolor[]    = "#FF0000";
static char selscrbordercolor[]     = "#FF8800";
static char *colors[][3] = {
        /*                    fg           bg           border   */
        [SchemeNorm]      = { normfgcolor, normbgcolor, normbordercolor },
        [SchemeSel]       = { normfgcolor,  normbgcolor,  selbordercolor  },
        [SchemeStatus]    = { normfgcolor, normbgcolor,  normbordercolor  }, // Statusbar right {text,background,not used but cannot be empty}
        [SchemeTagsSel]   = { selfgcolor, selbgcolor,  selbordercolor  }, // Tagbar left selected {text,background,not used but cannot be empty}
        [SchemeTagsNorm]  = { normfgcolor, normbgcolor, normbordercolor  }, // Tagbar left unselected {text,background,not used but cannot be empty}
        [SchemeInfoSel]   = { selfgcolor, selbgcolor,  selbordercolor  }, // infobar middle  selected {text,background,not used but cannot be empty}
        [SchemeInfoNorm]  = { normfgcolor, normbgcolor,  normbordercolor  }, // infobar middle  unselected {text,background,not used but cannot be empty}
      	[SchemeScratchSel]  = { selfgcolor, selbgcolor,   selscrbordercolor },
        [SchemeScratchNorm] = { normfgcolor, normbgcolor,  normscrbordercolor },
};

/* autostart applications */
static const char *const autostart[] = {
  "picom", "-b", NULL,
  "load-wallpaper", NULL,
  "dwmblocks", NULL,
  "wired", NULL,
  /* "Discord", NULL, */
  "greenclip", "daemon", NULL,
   NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class              instance    title           tags mask     allowkill   isfloating  isterminal  noswallow  monitor   scratch key */
	// { NULL,               NULL,       NULL,           0,            1,          0,          0,          1,         0,        0  }, /* xev */
	{ "Weston Compositor",NULL,       NULL,           0,            1,          1,          0,          0,         -1,       0 },
	{ "neovim",           NULL,       NULL,           1 << 1,       1,          0,          0,          0,         -1,       0 },
	{ "librewolf",        NULL,       NULL,           1 << 2,       1,          0,          0,          0,         -1,       0 },
	{ "qutebrowser",      NULL,       NULL,           1 << 3,       1,          0,          0,          0,         -1,       0 },
	{ "discord",          NULL,       NULL,           1 << 4,       1,          0,          0,          0,         -1,       0 },
	{ "Spotify",          NULL,       NULL,           1 << 5,       1,          0,          0,          0,         -1,       0 },
	{ "Chromium",         NULL,       NULL,           1 << 6,       1,          0,          0,          0,         -1,       0 },
	{ "steam",            NULL,       NULL,           1 << 7,       1,          1,          0,          0,         -1,       0 },
	{ "steam",            NULL,       NULL,           1 << 7,       1,          1,          0,          0,         -1,       0 },
	{ "mpv",              NULL,       NULL,           1 << 8,       1,          0,          0,          0,         -1,       0 },
	{ "Nemo",             NULL,       NULL,           0,            1,          0,          1,          0,         -1,       0 },
	{ "St",               NULL,       NULL,           0,            1,          0,          1,          0,         -1,       0 },
	{ NULL,               NULL,       "spterm",       0,            1,          1,          1,          0,         0,       't' },
	{ "Nsxiv",            NULL,       NULL,           0,            1,          1,          1,          0,         0,       'w' },
	{ NULL,               NULL,       "random",       0,            1,          1,          0,          1,         0,       'o' },
	{ NULL,               NULL,       "random1",      0,            1,          1,          0,          1,         0,       'i' },
	{ NULL,               NULL,       "spmix",        0,            1,          1,          0,          1,         0,       'a' },
	{ NULL,               NULL,       "spcal",        0,            1,          1,          0,          1,         0,       'm' },
	{ NULL,               NULL,       "sptop",        0,            1,          1,          0,          1,         0,       'p' },
	{ NULL,               NULL,       "Event Tester", 0,            1,          0,          0,          1,         -1,        0  }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "HHH",      grid },
	{ "[B]",      bottomstack },
	{ "[D]",      deck },
};

/* static const Layout layouts[] = { */
/* 	/* symbol     arrange function */ 
/* 	{ "󰕰",      tile },    /* first entry is default */
/* 	{ "󰖲",      NULL },    /* no layout function means floating behavior */
/* 	{ "󰝤",      monocle }, */
/* }; */

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      previewtag,     {.ui = TAG } },     \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "st", NULL };
static const char *layoutmenu_cmd = "~/.local/bin/layoutmenu.sh";

static const char *volumecmd[3][5] = {
	{ "wpctl", "set-volume", "@DEFAULT_SINK@", "0.05+", NULL },
	{ "wpctl", "set-volume", "@DEFAULT_SINK@", "0.05-", NULL },
	{ "wpctl", "set-mute", "@DEFAULT_SINK@", "toggle", NULL },
};

static const char *playerctlcmd[3][3] = {
	{ "playerctl", "play-pause", NULL },
	{ "playerctl", "next", NULL },
	{ "playerctl", "previous", NULL },
};


/* scratchpads */
static const char *sptermcmd[] = {"t", "st", "-t", "spterm","-g", "120x24", NULL};
static const char *spwpcmd[]   = {"w", "set-wallpaper", NULL};
static const char *sptopcmd[]  = {"p", "st", "-t", "sptop", "-g", "120x24", "-e", "btop", NULL};
static const char *spmixcmd[]  = {"a", "st", "-t", "spmix", "-g", "120x24", "-e", "pulsemixer", NULL};
static const char *spcalcmd[]  = {"m", "st", "-t", "spcal", "-g", "120x24", "-e", "calcurse", NULL};
static const char *sprandomcmd[] = { "o",  NULL };
static const char *sprandom1cmd[] = { "i",  NULL };


static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_z,                     spawn,          SHCMD("bash ~/.local/bin/launcher") },
	{ MODKEY,                       XK_x,                     spawn,          SHCMD("bash ~/.local/bin/powermenu")},
	{ MODKEY|ShiftMask,             XK_w,                     spawn,          SHCMD("bash ~/.local/bin/waldl")},
	{ MODKEY|ShiftMask,             XK_d,                     spawn,          SHCMD("bash ~/.local/bin/display_chose")},
	{ MODKEY|ShiftMask,             XK_e,                     spawn,          SHCMD("bash ~/.local/bin/anime")},
	{ MODKEY|ShiftMask,             XK_t,                     spawn,          SHCMD("bash ~/.local/bin/theme_picker.sh")},
	{ MODKEY,                       XK_v,                     spawn,          SHCMD("~/.local/bin/greenclip print | grep . | dmenu -m 0 | xargs -r -d'\n' -I '{}' greenclip print '{}'")},
	{0,                             XK_Print,       		  spawn,          SHCMD("bash ~/.local/bin/screenshot_dmenu")},
	{ShiftMask,                     XK_Print,       		  spawn,          SHCMD("bash ~/.local/bin/screenshot_dmenu_c")},
	{ MODKEY,                       XK_Return,                spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_n,                     spawn,          SHCMD("st -c neovim -e nvim")},
	{ShiftMask,                     XK_F12,                   spawn,          {.v = volumecmd[0]} },
	{ShiftMask,                     XK_F11,                   spawn,          {.v = volumecmd[1]} },
 	{ShiftMask,                     XK_F10,                   spawn,          {.v = volumecmd[2]} },
	{ShiftMask,                     XK_F8,                    spawn,          {.v = playerctlcmd[0]} },
 	{ShiftMask,                     XK_F9,                    spawn,          {.v = playerctlcmd[1]} },
 	{ShiftMask,                     XK_F7,                    spawn,          {.v = playerctlcmd[2]} },
	{ MODKEY,                       XK_b,                     togglebar,      {0} },
	{ MODKEY,                       XK_j,                     focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,                     focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_u,                     incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,                     incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,                     setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,                     setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_h,                     shiftview,      { .i = -1 } },
	{ MODKEY,                       XK_l,                     shiftview,      { .i = +1 } },
	{ MODKEY|ShiftMask,             XK_Return,                zoom,           {0} },
	{ MODKEY,                       XK_Tab,                   view,           {0} },
	{ MODKEY,                       XK_q,                     killclient,     {0} },
	{ MODKEY,                       XK_t,                     setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                     setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                     setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,                 layoutmenu,       {0} },
	{ MODKEY|ShiftMask,             XK_space,                 togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,                     togglefullscr,  {0} },
    { MODKEY,                       XK_s,                     togglesticky,   {0} },
	{ MODKEY,                       XK_0,                     view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                     tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                 focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                 tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                tagmon,         {.i = +1 } },

	{ MODKEY,                       XK_minus,                 setgaps,        {.i = -2 } },
	{ MODKEY,                       XK_equal,                 setgaps,        {.i = +2 } },
	{ MODKEY|ShiftMask,             XK_minus,                 setgaps,        {.i = 0  } },
	{ MODKEY|ShiftMask,             XK_equal,                 setgaps,        {.i = -999 } },

	{ MODKEY,                       XK_F5,                    xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Escape,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_Escape,      quit,           {1} }, 


	{ MODKEY,                       XK_Escape,  togglescratch,  {.v = sptermcmd } },
	{ MODKEY,                       XK_a,      togglescratch,  {.v = spmixcmd } },
	{ MODKEY,                       XK_p,      togglescratch,  {.v = sptopcmd } },
	{ MODKEY,                       XK_w,      togglescratch,  {.v = spwpcmd } },
	{ MODKEY,                       XK_c,      togglescratch,  {.v = spcalcmd } },

	{ MODKEY,                       XK_o,      togglescratch,  {.v = sprandomcmd } },
	{ MODKEY|ShiftMask,             XK_o,      setscratch,     {.v = sprandomcmd } },
	{ MODKEY|ControlMask,           XK_o,      removescratch,  {.v = sprandomcmd } },

	{ MODKEY,                       XK_i,      togglescratch,  {.v = sprandom1cmd } },
	{ MODKEY|ShiftMask,             XK_i,      setscratch,     {.v = sprandom1cmd } },
	{ MODKEY|ControlMask,           XK_i,      removescratch,  {.v = sprandom1cmd } },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button3,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
