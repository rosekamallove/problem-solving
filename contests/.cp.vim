let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Contest
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
argglobal
%argdel
$argadd A.cpp
tabnew
tabnew
tabnew
tabrewind
edit A.cpp
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
2wincmd k
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
exe 'vert 1resize ' . ((&columns * 65 + 50) / 100)
exe '2resize ' . ((&lines * 15 + 28) / 56)
exe 'vert 2resize ' . ((&columns * 34 + 50) / 100)
exe '3resize ' . ((&lines * 16 + 28) / 56)
exe 'vert 3resize ' . ((&columns * 34 + 50) / 100)
exe '4resize ' . ((&lines * 20 + 28) / 56)
exe 'vert 4resize ' . ((&columns * 34 + 50) / 100)
tcd ~/Contest
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
let s:l = 34 - ((9 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 34
normal! 06|
wincmd w
argglobal
if bufexists("~/Contest/.zin.txt") | buffer ~/Contest/.zin.txt | else | edit ~/Contest/.zin.txt | endif
balt ~/Contest/A.cpp
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
if bufexists("~/Contest/.zot.md") | buffer ~/Contest/.zot.md | else | edit ~/Contest/.zot.md | endif
balt ~/Contest/A.cpp
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
let s:l = 1 - ((0 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("~/Contest/.deb.txt") | buffer ~/Contest/.deb.txt | else | edit ~/Contest/.deb.txt | endif
balt ~/Contest/.zdf.txt
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
let s:l = 1 - ((0 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 65 + 50) / 100)
exe '2resize ' . ((&lines * 15 + 28) / 56)
exe 'vert 2resize ' . ((&columns * 34 + 50) / 100)
exe '3resize ' . ((&lines * 16 + 28) / 56)
exe 'vert 3resize ' . ((&columns * 34 + 50) / 100)
exe '4resize ' . ((&lines * 20 + 28) / 56)
exe 'vert 4resize ' . ((&columns * 34 + 50) / 100)
tabnext
edit ~/Contest/B.cpp
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
2wincmd k
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
exe 'vert 1resize ' . ((&columns * 65 + 50) / 100)
exe '2resize ' . ((&lines * 15 + 28) / 56)
exe 'vert 2resize ' . ((&columns * 34 + 50) / 100)
exe '3resize ' . ((&lines * 16 + 28) / 56)
exe 'vert 3resize ' . ((&columns * 34 + 50) / 100)
exe '4resize ' . ((&lines * 20 + 28) / 56)
exe 'vert 4resize ' . ((&columns * 34 + 50) / 100)
argglobal
balt ~/Contest/A.cpp
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
let s:l = 34 - ((9 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 34
normal! 06|
wincmd w
argglobal
if bufexists("~/Contest/.zin.txt") | buffer ~/Contest/.zin.txt | else | edit ~/Contest/.zin.txt | endif
balt ~/Contest/B.cpp
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
if bufexists("~/Contest/.zot.md") | buffer ~/Contest/.zot.md | else | edit ~/Contest/.zot.md | endif
balt ~/Contest/B.cpp
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
let s:l = 1 - ((0 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("~/Contest/.deb.txt") | buffer ~/Contest/.deb.txt | else | edit ~/Contest/.deb.txt | endif
balt ~/Contest/B.cpp
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
let s:l = 1 - ((0 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 65 + 50) / 100)
exe '2resize ' . ((&lines * 15 + 28) / 56)
exe 'vert 2resize ' . ((&columns * 34 + 50) / 100)
exe '3resize ' . ((&lines * 16 + 28) / 56)
exe 'vert 3resize ' . ((&columns * 34 + 50) / 100)
exe '4resize ' . ((&lines * 20 + 28) / 56)
exe 'vert 4resize ' . ((&columns * 34 + 50) / 100)
tabnext
edit ~/Contest/C.cpp
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
2wincmd k
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
exe 'vert 1resize ' . ((&columns * 65 + 50) / 100)
exe '2resize ' . ((&lines * 15 + 28) / 56)
exe 'vert 2resize ' . ((&columns * 34 + 50) / 100)
exe '3resize ' . ((&lines * 16 + 28) / 56)
exe 'vert 3resize ' . ((&columns * 34 + 50) / 100)
exe '4resize ' . ((&lines * 20 + 28) / 56)
exe 'vert 4resize ' . ((&columns * 34 + 50) / 100)
argglobal
balt ~/Contest/B.cpp
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
let s:l = 34 - ((9 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 34
normal! 06|
wincmd w
argglobal
if bufexists("~/Contest/.zin.txt") | buffer ~/Contest/.zin.txt | else | edit ~/Contest/.zin.txt | endif
balt ~/Contest/.zdf.txt
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
if bufexists("~/Contest/.zot.md") | buffer ~/Contest/.zot.md | else | edit ~/Contest/.zot.md | endif
balt ~/Contest/C.cpp
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
let s:l = 1 - ((0 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("~/Contest/.deb.txt") | buffer ~/Contest/.deb.txt | else | edit ~/Contest/.deb.txt | endif
balt ~/Contest/C.cpp
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
let s:l = 1 - ((0 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 65 + 50) / 100)
exe '2resize ' . ((&lines * 15 + 28) / 56)
exe 'vert 2resize ' . ((&columns * 34 + 50) / 100)
exe '3resize ' . ((&lines * 16 + 28) / 56)
exe 'vert 3resize ' . ((&columns * 34 + 50) / 100)
exe '4resize ' . ((&lines * 20 + 28) / 56)
exe 'vert 4resize ' . ((&columns * 34 + 50) / 100)
tabnext
edit ~/Contest/D.cpp
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
2wincmd k
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
exe 'vert 1resize ' . ((&columns * 65 + 50) / 100)
exe '2resize ' . ((&lines * 15 + 28) / 56)
exe 'vert 2resize ' . ((&columns * 34 + 50) / 100)
exe '3resize ' . ((&lines * 16 + 28) / 56)
exe 'vert 3resize ' . ((&columns * 34 + 50) / 100)
exe '4resize ' . ((&lines * 20 + 28) / 56)
exe 'vert 4resize ' . ((&columns * 34 + 50) / 100)
argglobal
balt ~/Contest/C.cpp
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
let s:l = 34 - ((9 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 34
normal! 06|
wincmd w
argglobal
if bufexists("~/Contest/.zin.txt") | buffer ~/Contest/.zin.txt | else | edit ~/Contest/.zin.txt | endif
balt ~/Contest/D.cpp
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
if bufexists("~/Contest/.zot.md") | buffer ~/Contest/.zot.md | else | edit ~/Contest/.zot.md | endif
balt ~/Contest/D.cpp
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
let s:l = 1 - ((0 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("~/Contest/.deb.txt") | buffer ~/Contest/.deb.txt | else | edit ~/Contest/.deb.txt | endif
balt ~/Contest/D.cpp
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
let s:l = 1 - ((0 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 65 + 50) / 100)
exe '2resize ' . ((&lines * 15 + 28) / 56)
exe 'vert 2resize ' . ((&columns * 34 + 50) / 100)
exe '3resize ' . ((&lines * 16 + 28) / 56)
exe 'vert 3resize ' . ((&columns * 34 + 50) / 100)
exe '4resize ' . ((&lines * 20 + 28) / 56)
exe 'vert 4resize ' . ((&columns * 34 + 50) / 100)
tabnext 1
badd +34 ~/Contest/A.cpp
badd +21 ~/Contest/B.cpp
badd +20 ~/Contest/C.cpp
badd +28 ~/Contest/D.cpp
badd +1 ~/Contest/.zin.txt
badd +1 ~/Contest/.zot.md
badd +1 ~/Contest/.deb.txt
badd +1 ~/Contest/.zdf.txt
badd +27 ~/Contest/E.cpp
badd +1 ~/Contest/.zex.txt
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOSAc
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
