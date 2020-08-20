set ts=4
set sw=4
set autoindent
set softtabstop=4
set backspace=indent,eol,start
set backspace=2
set expandtab
set number
set relativenumber
set hls
set ruler
syntax on

inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {{ {
inoremap {} {}

autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -std=c++17 -Wshadow -Wall % -o %:r -O2 -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <F8> :!%:r<CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s /^\(\s*\)\/\/\/\//\1<CR> $

set guifont=Consolas:h12
colorscheme molokai

autocmd BufNewFile *.cpp 0r C:\Users\ljuba\template.cpp
