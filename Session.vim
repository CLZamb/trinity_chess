let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Code/c++/trinity_engine
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 tests/g_test.cpp
badd +1 ~/Code/c++/trinity_engine/src/cli/game/game.cpp
badd +1 ~/Code/c++/trinity_engine/src/cli/ui/graphics/ui_messages/game_messages.hpp
badd +115 ~/Code/c++/trinity_engine/src/cli/board/fen/board_fen_controller.cpp
badd +19 ~/Code/c++/trinity_engine/src/cli/board/fen/board_fen_model.h
badd +1 ~/Code/c++/trinity_engine/src/cli/board/fen/board_fen_model.cpp
badd +10 ~/Code/c++/trinity_engine/src/cli/board/board_representation/board.h
badd +12 ~/Code/c++/trinity_engine/src/cli/game/turn/game_turn_observer.h
badd +8 ~/Code/c++/trinity_engine/src/cli/board/fen/fen_model.hpp
badd +4 src/cli/board/fen/CMakeLists.txt
badd +117 ~/Code/c++/trinity_engine/src/cli/board/board_representation/board.cpp
badd +74 ~/Code/c++/trinity_engine/src/cli/utils/string_utils.h
badd +31 ~/Code/c++/trinity_engine/src/cli/ui/graphics/board/board_ui.h
badd +1 src/cli/ui/graphics/board/board_ui.cpp
badd +4 ~/Code/c++/trinity_engine/src/cli/ui/graphics/board/decorators/IUi_board.h
badd +9 ~/Code/c++/trinity_engine/src/cli/ui/graphics/board/CMakeLists.txt
badd +8 src/cli/ui/graphics/board/board_controller.h
badd +3 ~/Code/c++/trinity_engine/src/cli/ui/graphics/board/board_view.h
badd +1065 /usr/include/c++/12.2.1/bits/unique_ptr.h
badd +1 ~/Code/c++/trinity_engine/src/cli/ui/graphics/board/board_controller.cpp
badd +66 ~/Code/c++/trinity_engine/src/cli/ui/graphics/board/board_view.cpp
badd +17 tests/another_test.cpp
badd +27 tests/CMakeLists.txt
argglobal
%argdel
$argadd tests/g_test.cpp
set lines=53 columns=234
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit tests/g_test.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
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
wincmd =
argglobal
balt ~/Code/c++/trinity_engine/src/cli/board/fen/fen_model.hpp
let s:l = 15 - ((14 * winheight(0) + 25) / 50)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 15
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("tests/CMakeLists.txt", ":p")) | buffer tests/CMakeLists.txt | else | edit tests/CMakeLists.txt | endif
if &buftype ==# 'terminal'
  silent file tests/CMakeLists.txt
endif
balt tests/another_test.cpp
let s:l = 27 - ((26 * winheight(0) + 24) / 49)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 27
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("~/Code/c++/trinity_engine/src/cli/game/game.cpp", ":p")) | buffer ~/Code/c++/trinity_engine/src/cli/game/game.cpp | else | edit ~/Code/c++/trinity_engine/src/cli/game/game.cpp | endif
if &buftype ==# 'terminal'
  silent file ~/Code/c++/trinity_engine/src/cli/game/game.cpp
endif
balt tests/CMakeLists.txt
let s:l = 1 - ((0 * winheight(0) + 24) / 49)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
3wincmd w
wincmd =
tabnext
argglobal
if bufexists(fnamemodify("term://~/Code/c++/trinity_engine//950041:/bin/zsh", ":p")) | buffer term://~/Code/c++/trinity_engine//950041:/bin/zsh | else | edit term://~/Code/c++/trinity_engine//950041:/bin/zsh | endif
if &buftype ==# 'terminal'
  silent file term://~/Code/c++/trinity_engine//950041:/bin/zsh
endif
balt ~/Code/c++/trinity_engine/src/cli/game/game.cpp
let s:l = 49 - ((48 * winheight(0) + 24) / 49)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 49
normal! 0
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
