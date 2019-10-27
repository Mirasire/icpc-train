" - For Neovim: stdpath('data') . '/plugged'
" - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.vim/plugged')

"--------------------------------------------------------------------------
"vim-tagbar
"--------------------------------------------------------------------------

"Plug 'majutsushi/tagbar'

"--------------------------------------------------------------------------
"vim-Markdown-Perview
"--------------------------------------------------------------------------
"
"Plug 'JamshedVesuna/vim-markdown-preview'
"let vim_markdown_preview_toggle=1

"--------------------------------------------------------------------------
"vim-LATEX
"--------------------------------------------------------------------------
"
Plug 'lervag/vimtex'
let g:tex_flavor='latex'
let g:vimtex_view_method='zathura'
let g:vimtex_quickfix_mode=0
set conceallevel=1
let g:tex_conceal='abdmg'

"--------------------------------------------------------------------------
"vim-airline
"--------------------------------------------------------------------------

"Plug 'vim-airline/vim-airline'
"Plug 'vim-airline/vim-airline-themes'
"let g:airline_theme="deus"

"这个是安装字体后 必须设置此项"
let g:airline_powerline_fonts = 1

"set guifont=Consolas\ for\ Powerline\ FixedD:h11
if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif
" old vim-powerline symbols
let g:airline_section_b = '%{strftime("%c")}'
let g:airline_section_y = 'BN: %{bufnr("%")}'
let g:airline_left_sep = '⮀'
let g:airline_left_alt_sep = '⮁'
let g:airline_right_sep = '⮂'
let g:airline_right_alt_sep = '⮃'
let g:airline_symbols.branch = '⭠'
let g:airline_symbols.readonly = '⭤'

"themes
Plug 'chriskempson/base16-vim'
Plug 'morhetz/gruvbox'

"dracula
Plug 'dracula/vim', { 'as': 'dracula' }

" Make sure you use single quotes

" Shorthand notation; fetches https://github.com/junegunn/vim-easy-align
Plug 'junegunn/vim-easy-align'

" Any valid git URL is allowed
Plug 'https://github.com/junegunn/vim-github-dashboard.git'

" Multiple Plug commands can be written in a single line using | separators
Plug 'SirVer/ultisnips' | Plug 'honza/vim-snippets'

" On-demand loading
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }

call plug#end()

"set rtp+=/home/meskill/.local/lib/python2.7/site-packages/powerline/bindings/vim
"
"" These lines setup the environment to show graphics and colors correctly.
"
"set nocompatible
"
"set t_Co=256
"
"let g:minBufExplForceSyntaxEnable = 1
"
"if ! has('gui_running')
"
"set ttimeoutlen=10
"
"augroup FastEscape
"
"autocmd!
"
"au InsertEnter * set timeoutlen=0
"
"au InsertLeave * set timeoutlen=1000
"
"augroup END
"
"endif
"
"set laststatus=2 " Always display the statusline in all windows
"
"set guifont=Inconsolata\ for\ Powerline:h14
"
"set noshowmode " Hide the default mode text (e.g. -- INSERT -- below the statusline)

"主题
"colorschem onedark
"syntax enable
"colorscheme monokai
"colorscheme dracula
colorschem gruvbox
set bg=dark
"colorscheme solarized
"set background=light

"设置背景透明
"hi Normal ctermfg=252 ctermbg=none

"设置行高光
set cursorline

"{} 自动补全
inoremap { {}<ESC>i

"cpp auto code
autocmd BufNewFile *.cpp exec ":call SetTitle()"

func SetTitle()

		"call setline(1,"//".strftime("%Y-%m-%d"))
		call setline(1,"#include <iostream>")
		call setline(2,"#include <algorithm>")
		call setline(3,"#include <cstdio>")
		call setline(4,"#include <cstring>")
		call setline(5,"#include <string>")
		call setline(6,"using namespace std;")
		call setline(7,"")
		call setline(8,"")
		call setline(9,"int main() {")
		call setline(10,"	return 0;")
		call setline(11,"}")
		call cursor(7,1)

endfunc
