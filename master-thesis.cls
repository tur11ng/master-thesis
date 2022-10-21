\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{master-thesis}[Master thesis template for university of Patras]
\LoadClass[12pt]{report}
\usepackage[a4paper,
top=2cm,bottom=2cm,left=2.5cm,right=2.5cm,
headheight=10pt,headsep=1cm,footskip=1cm,
includehead,includefoot]{geometry}

\usepackage[final]{graphicx}
\usepackage{textcase}
\usepackage{etoolbox}
\usepackage[colorlinks]{hyperref}
\usepackage{tabularx}
\usepackage{longtable}
\usepackage[toc,page,titletoc]{appendix}
\usepackage{setspace}
\usepackage{amsmath}
\usepackage{bm}
\usepackage{amsbsy}
\usepackage{sectsty}
\usepackage{comment}
\usepackage{mathtools}
\usepackage{fontspec}
\usepackage{polyglossia}
\usepackage{xgreek}
\usepackage{float}
\usepackage{url}
\usepackage[table,xcdraw,xelat,dvipsnames]{xcolor}
\usepackage{enumitem}
\usepackage{circuitikz}
\usepackage{diagbox}
\usepackage{xfrac}
\usepackage{mdframed}
\usepackage[singlelinecheck=false]{caption}
\usepackage{listings}
\usepackage[outputdir=out]{minted}
\usepackage{amsthm, amssymb}
\usepackage[warnings-off={mathtools-colon,mathtools-overbracket}]{unicode-math}
\usepackage[nonumberlist, acronym, automake]{glossaries-extra}
\usepackage[colorinlistoftodos,prependcaption,textsize=tiny]{todonotes}
\usepackage{subfig}
\usepackage{pmboxdraw}
\usepackage[
    n,
    operators,
    advantage,
    sets,
    adversary,
    landau,
    probability,
    notions,    
    logic,
    ff,
    mm,
    primitives,
    events,
    complexity,
    asymptotics,
    keys]{cryptocode}
\usepackage{dashbox}
\usepackage[most]{tcolorbox}
\usepackage{xargs}
\usepackage[autostyle]{csquotes}
\usepackage[full,
    classfont=roman,
    langfont=roman,
    funcfont=roman]{complexity}
\usepackage{fancyhdr}
\usepackage[bottom]{footmisc}

\pagestyle{fancy}
\fancyhf{}
\fancyhead[C]{}
\fancyhead[LO,RE]{Μελέτη Πρωτοκόλλων Ασφαλούς Υπολογισμού Πολλών Μερών}
\fancyfoot[C]{}
\fancyfoot[RO,LE]{\thepage}
\fancyfoot[LO,RE]{Θεόδωρος Συμεωνίδης Α.Μ. 1064870}
\renewcommand{\footrulewidth}{0.4pt}

\setdefaultlanguage{greek}
\setotherlanguages{english}
\setmainfont[Kerning=On]{Linux Libertine O}
\setsansfont[Kerning=On]{Linux Libertine O}
\setromanfont[Kerning=On]{Linux Libertine O}
\newfontfamily\greekfont[Script=Greek]{Linux Libertine O}
\newfontfamily\greekfontsf[Script=Greek]{Linux Libertine O}
\newfontfamily{\greekfonttt}{Linux Libertine O}
\setlength{\marginparwidth }{2cm}

\onehalfspacing

\newcommand{\unchapter}[1]{
  \begingroup
  \let\@makechapterhead\@gobble
  \chapter{#1}
  \endgroup
}

\theoremstyle{definition}
\newtheorem{definition}{Definition}[section]

\setcounter{tocdepth}{3}
\setcounter{secnumdepth}{3}

\newcommandx{\unsure}[2][1=]{\todo[linecolor=red,backgroundcolor=red!25,bordercolor=red,#1]{#2}}
\newcommandx{\change}[2][1=]{\todo[linecolor=blue,backgroundcolor=blue!25,bordercolor=blue,#1]{#2}}
\newcommandx{\info}[2][1=]{\todo[linecolor=OliveGreen,backgroundcolor=OliveGreen!25,bordercolor=OliveGreen,#1]{#2}}
\newcommandx{\improvement}[2][1=]{\todo[linecolor=Plum,backgroundcolor=Plum!25,bordercolor=Plum,#1]{#2}}
\newcommandx{\thiswillnotshow}[2][1=]{\todo[disable,#1]{#2}}

\newcommand{\highlight}[2]{\colorbox{#1}{$\displaystyle #2$}}
\definecolor{Light-gray}{gray}{0.8}

\newcommand\scalemath[2]{\scalebox{#1}{\mbox{\ensuremath{\displaystyle #2}}}}

\newcommand\pn[2]{#1_n #2^n + \cdots + #1_1 #2 + #1_0}

\newlang{\UNSAT}{UNSAT}
\newclass{\dIP}{dIP}

\createpseudocodeblock{pcb}{center,boxed}{}{}{}
\createprocedureblock{procb}{center, boxed}{}{}{linenumbering}

\newcommand{\oracle}{\mathcal{O}}

\newcommand{\EN}[1]{\foreignlanguage{english}{#1}}

\newenvironment{longlisting}{\captionsetup{type=figure}}{}

\patchcmd{\definition}{Definition}{Ορισμός}{}{}
\patchcmd{\theorem}{Theorem}{Θεώρημα}{}{}
\makeatletter
% Grab the old \addcontentsline, which has been already being redefined by hyperref (eventually)
\let\latex@@addcontentsline\addcontentsline

\AtBeginDocument{%
    \renewcommand{\addcontentsline}[3]{%
        \def\@@zzz{#1}\def\@@zxx{lol}
        \latex@@addcontentsline{%
            \ifx\@@zzz\@@zxx lof\else #1\fi
        }{#2}{#3}%
    }

    \renewcommand\lstlistingname{Slika}
    \let\l@lstlisting\l@figure
    \let\c@lstlisting\c@figure
    \let\thelstlisting\thefigure
    \let\ftype@lstlisting\ftype@figure
}
\makeatother

\makeglossaries