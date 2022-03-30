mkdir ~/Documents/problem-solving/contests/$1
cd ~/Documents/problem-solving/contests/$1
touch {A..D}.cpp
cat ~/.vim/templates/code.cpp >> {A..D}.cpp
touch .zin.txt .zot.txt .zdf.txt .zex.txt .deb.txt
cp ~/Contest/.cp.vim ./
vim -S .cp.vim
