int height, width;
bool visited[1000][1000];
bool blocked[1000][1000];

bool valid(int x, int y){
    if(x<0 or y<0 or x>=height or y>=width or visited[x][y] or blocked[x][y]){
        return false;
    } 
    return true;
}

bool find_path(int x, int y, int ex, int ey){
    if(!valid(x,y)){
        return false;
    }
    visited[x][y] = true;
    if(x == ex and y== ey){/*Reached*/
        return true;
    }

    bool found = false;
    if(find_path(x+1, y, ex, ey))
        found = true;
    if(find_path(x-1, y, ex, ey))
        found = true;
    if(find_path(x, y+1, ex, ey))
        found = true;
    if(find_path(x, y-1, ex, ey))
        found = true;
    return found;
}
