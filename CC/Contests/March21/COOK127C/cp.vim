let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Documents/Competitve/CC/Contests/March21/COOK127C
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
argglobal
%argdel
$argadd Pawri_Meme.cpp
edit Pawri_Meme.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd _ | wincmd |
split
wincmd _ | wincmd |
split
wincmd _ | wincmd |
split
3wincmd k
wincmd w
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 95 + 70) / 140)
exe '2resize ' . ((&lines * 15 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 44 + 70) / 140)
exe '3resize ' . ((&lines * 15 + 32) / 65)
exe 'vert 3resize ' . ((&columns * 44 + 70) / 140)
exe '4resize ' . ((&lines * 15 + 32) / 65)
exe 'vert 4resize ' . ((&columns * 44 + 70) / 140)
exe '5resize ' . ((&lines * 14 + 32) / 65)
exe 'vert 5resize ' . ((&columns * 44 + 70) / 140)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 32 - ((31 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 32
normal! 028|
wincmd w
argglobal
if bufexists("input.txt") | buffer input.txt | else | edit input.txt | endif
balt Pawri_Meme.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 4 - ((3 * winheight(0) + 7) / 15)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 4
normal! 022|
wincmd w
argglobal
if bufexists("output.txt") | buffer output.txt | else | edit output.txt | endif
balt Pawri_Meme.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 7) / 15)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("expected.txt") | buffer expected.txt | else | edit expected.txt | endif
balt Pawri_Meme.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 3 - ((2 * winheight(0) + 7) / 15)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 3
normal! 0
wincmd w
argglobal
if bufexists("diff.txt") | buffer diff.txt | else | edit diff.txt | endif
balt Pawri_Meme.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 7) / 14)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 95 + 70) / 140)
exe '2resize ' . ((&lines * 15 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 44 + 70) / 140)
exe '3resize ' . ((&lines * 15 + 32) / 65)
exe 'vert 3resize ' . ((&columns * 44 + 70) / 140)
exe '4resize ' . ((&lines * 15 + 32) / 65)
exe 'vert 4resize ' . ((&columns * 44 + 70) / 140)
exe '5resize ' . ((&lines * 14 + 32) / 65)
exe 'vert 5resize ' . ((&columns * 44 + 70) / 140)
tabnext 1
badd +10 Pawri_Meme.cpp
badd +0 input.txt
badd +0 output.txt
badd +0 expected.txt
badd +0 diff.txt
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOSA
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
