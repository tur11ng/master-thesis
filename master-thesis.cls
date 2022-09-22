\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{master-thesis}[Master thesis template for university of Patras]
\LoadClass[12pt]{report}
\usepackage[a4paper,
top=2cm,bottom=2cm,bindingoffset=0.5cm,left=2cm,right=2cm,
headheight=15pt,headsep=1.25cm,footskip=1.25cm,
includehead,includefoot]{geometry}

\usepackage{fancyhdr}
\usepackage[final]{graphicx}
\usepackage{textcase}
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
\usepackage{caption}
\usepackage{listings}
\usepackage{minted}
\usepackage{amsthm, amssymb}
\usepackage[warnings-off={mathtools-colon,mathtools-overbracket}]{unicode-math}
\usepackage[acronym]{glossaries}
\usepackage[colorinlistoftodos,prependcaption,textsize=tiny]{todonotes}
\usepackage{subfig}
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
\newtheorem{theorem}{Theorem}

\newglossaryentry{maths}
{
    name=mathematics,
    description={Mathematics is what mathematicians do}
}

\newglossaryentry{latex}
{
    name=latex,
    description={Is a markup language specially suited for 
scientific documents}
}


\newglossaryentry{formula}
{
    name=formula,
    description={A mathematical expression}
}

\newacronym{gcd}{GCD}{Greatest Common Divisor}
\newacronym{lcm}{LCM}{Least Common Multiple}

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

\newenvironment{longlisting}{\captionsetup{type=listing}}{}
