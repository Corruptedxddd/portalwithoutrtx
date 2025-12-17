#include <stdio.h>
#include <curses.h>
char map[120][120];

int main(){
    int resets=0;
    int character;
    int y=10;
    int x=10;
    int rows;
    int cols;
    char cube='@';
    char plate='X';
    char red='O';
    char blue='O';
    int bluex=35;
    int bluey=9;
    int redx=23;
    int redy=9;
    int platex=35;
    int platey=11;
    int cubex=35;
    int cubey=15;
    bool win=false;
    bool firstboot=false;
    initscr();
    keypad(stdscr,1);
    noecho();
    curs_set(0);
    getmaxyx(stdscr,rows,cols);
    char lastchar='>';
    //LVL1
    do {
        start_color();
        init_pair(1,COLOR_BLUE,COLOR_BLACK);
        init_pair(2,COLOR_RED,COLOR_BLACK);
        init_pair(3,COLOR_MAGENTA,COLOR_BLACK);
        init_pair(4,COLOR_CYAN,COLOR_BLACK);
        if(x==41&&y==18){
            break;
        }
        if(x==41&&y==19){
            break;
        }
        if(cubex==platex&&cubey==platey){
            
            win=true;
        }else{
            win=false;
        }

        // MAP
        for(int y2=0;y2<=rows;y2++){
            for (int x2=0;x2<=cols;x2++){
                map[y2][x2]='#';
                mvaddch(y2,x2,'#');
            }
        }

        for(int y2=10;y2<=20;y2++){
            for (int x2=10;x2<=40;x2++){
                map[y2][x2]=' ';
                mvaddch(y2,x2,' ');
            }

        }
        //RESET
        map[41][13]='R';
        mvaddch(13,41,'R' | COLOR_PAIR(4));
        //MAP MAKING BARIERS
        map[10][32]='|';
        mvaddch(10,32,'|');
        map[11][32]='|';
        mvaddch(11,32,'|');
        map[12][32]='|';
        mvaddch(12,32,'|');

        map[12][33]='-';
        mvaddch(12,33,'-');
        map[12][34]='-';
        mvaddch(12,34,'-');
        map[12][35]='-';
        mvaddch(12,35,'-');
        map[12][36]='-';
        mvaddch(12,36,'-');
        map[12][37]='-';
        mvaddch(12,37,'-');
        map[12][38]='-';
        mvaddch(12,38,'-');
        map[12][39]='-';
        mvaddch(12,39,'-');
        map[12][40]='-';
        mvaddch(12,40,'-');
        map[15][31]='-';
        mvaddch(15,31,'-');
        map[15][30]='-';
        mvaddch(15,30,'-');
        map[15][29]='-';
        mvaddch(15,29,'-');
        map[15][28]='|';
        mvaddch(15,28,'|');
        map[16][28]='|';
        mvaddch(16,28,'|');
        map[17][28]='|';
        mvaddch(17,28,'|');
        map[17][27]='-';
        mvaddch(17,27,'-');
        map[17][26]='-';
        mvaddch(17,26,'-');
        map[17][25]='-';
        mvaddch(17,25,'-');
        map[17][24]='-';
        mvaddch(17,24,'-');
        map[17][23]='-';
        mvaddch(17,23,'-');
        map[17][22]='-';
        mvaddch(17,22,'-');
        map[17][21]='-';
        mvaddch(17,21,'-');
        map[17][20]='-';
        mvaddch(17,20,'-');
        map[17][19]='-';
        mvaddch(17,19,'-');
        map[17][18]='|';
        mvaddch(17,18,'|');
        map[18][18]='|';
        mvaddch(18,18,'|');
        map[19][18]='|';
        mvaddch(19,18,'|');
        map[20][18]='|';
        mvaddch(20,18,'|');

        map[10][24]='|';
        mvaddch(10,24,'|');
        map[11][24]='|';
        mvaddch(11,24,'|');
        map[12][24]='|';
        mvaddch(12,24,'|');
        map[13][24]='|';
        mvaddch(13,24,'|');
        map[14][24]='|';
        mvaddch(14,24,'|');
        map[14][23]='-';
        mvaddch(14,23,'-');
        map[14][22]='-';
        mvaddch(14,22,'-');
        map[14][21]='-';
        mvaddch(14,21,'-');
        map[14][20]='-';
        mvaddch(14,20,'-');
        map[14][19]='-';
        mvaddch(14,19,'-');
        map[14][18]='-';
        mvaddch(14,18,'-');
        map[14][17]='-';
        mvaddch(14,17,'-');
        map[14][16]='-';
        mvaddch(14,16,'-');
        map[14][15]='|';
        mvaddch(14,15,'|');
        map[13][15]='|';
        mvaddch(13,15,'|');
        map[12][15]='|';
        mvaddch(12,15,'|');



        map[15][32]='|';
        mvaddch(15,32,'|');
        map[16][32]='|';
        mvaddch(16,32,'|');
        map[17][32]='|';
        mvaddch(17,32,'|');
        map[18][32]='|';
        mvaddch(18,32,'|');
        map[19][32]='|';
        mvaddch(19,32,'|');
        map[20][32]='|';
        mvaddch(20,32,'|');

        
        //DOORS
        map[20][41]='-';
        mvaddch(20,41,'-');
        //win door
        if(win==true){
            map[19][41]=' ';
            mvaddch(19,41,' ');
            map[18][41]=' ';
            mvaddch(18,41,' ');
        }else{
            map[19][41]='|';
            mvaddch(19,41,'|');
            map[18][41]='|';
            mvaddch(18,41,'|');
        }
        map[17][41]='-';
        mvaddch(17,41,'-');
        //PORTALS
        map[bluey][bluex]=blue;
        
        mvaddch(bluey,bluex,blue | COLOR_PAIR(1));
       
        map[redy][redx]=red;
        
        mvaddch(redy,redx,red | COLOR_PAIR(2));
        
        //plate
        map[platey][platex]=plate;
        mvaddch(platey,platex,plate);
        //cube
        map[cubey][cubex]=cube;
        mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
        //TEXT
        mvprintw(11,50," PORTAL WITHOUT RTX ");
        mvprintw(12,48," YOU DONT HAVE PORTAL GUN ");
        //mvprintw(13,48," Platex: %d ",platex);
        //mvprintw(14,48," Platey: %d ",platey);
        //mvprintw(15,48," cubex: %d ",cubex);
        //mvprintw(16,48," cubey: %d ",cubey);
        //mvprintw(17,48," GAMEOVER: %d ",gameovermap1);
        mvprintw(17,48," Test Chamber 1 ");
        mvprintw(18,48," CUBE RESETS : %d ",resets);
        mvprintw(19,48," SKIP CHAMBER : ESC ");
        //MOVEMENT
        if(firstboot==false){
            mvaddch(y,x,lastchar);
            firstboot=true;
            
        }
        if(character==KEY_UP&&map[y-1][x]==' '){
            y--;
            lastchar='^';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_DOWN&&map[y+1][x]==' '){
            y++;
            lastchar='v';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_LEFT&&map[y][x-1]==' '){
            x--;
            lastchar='<';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_RIGHT&&map[y][x+1]==' '){
            x++;
            lastchar='>';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_UP&&map[y-1][x]=='@'&&map[y-2][x]==' '){              //moving objs
            cubey--;
            y--;
            lastchar='^';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y+1][x]=='@'&&map[y+2][x]==' '){              //moving objs
            cubey++;
            y++;
            lastchar='v';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='@'&&map[y][x-2]==' '){              //moving objs
            cubex--;
            x--;
            lastchar='<';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='@'&&map[y][x+2]==' '){              //moving objs
            cubex++;
            x++;
            lastchar='>';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='@'&&map[y-2][x]=='O'){              //moving objs
            cubey=bluey+2;
            cubex=bluex;
            y--;
            lastchar='^';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT){
            if(x==40&&y==13){
                if(cubey!=14||cubex!=38){
                    cubey=14;
                    cubex=38;
                    resets++;
                    mvprintw(20,48," CUBE RESET ");
                    mvaddch(14,38,cube| COLOR_PAIR(3));
                }
                
            }
            mvaddch(y,x,lastchar);
           
        }else {
            mvaddch(y,x,lastchar);
        }
        mvprintw(10,55," x: %d y:%d ",x,y);
        
    }while((character=getch())!=27);
    //RESETING
    resets=0;
    y=10;
    x=10;
    char portalgun='t';
    int portalgunx=35;
    int portalguny=13;
    cube='@';
    plate='X';
    red='O';
    blue='O';
    bluex=9;
    bluey=15;
    redx=33;
    redy=9;
    platex=35;
    platey=22;
    cubex=22;
    cubey=12;
    int temp=0;
    firstboot=false;
    lastchar='>';
    bool hasportalgun=false;
    bool portalgunselection=false; //false=blue true=red
    //bool cake=false;
    win=false;
    //MAP2
    do {
        start_color();
        init_pair(1,COLOR_BLUE,COLOR_BLACK);
        init_pair(2,COLOR_RED,COLOR_BLACK);
        init_pair(3,COLOR_MAGENTA,COLOR_BLACK);
        init_pair(4,COLOR_CYAN,COLOR_BLACK);
        if(cubex==platex&&cubey==platey){
            win=true;
        }else{
            win=false;
        }
        if(x==66&&y==18){
            break;
        }
        if(x==66&&y==19){
            break;
        }
        
        // MAP making
        for(int y2=0;y2<=rows;y2++){
            for (int x2=0;x2<=cols;x2++){
                map[y2][x2]='#';
                mvaddch(y2,x2,'#');
            }
        }

        for(int y2=10;y2<=25;y2++){
            for (int x2=10;x2<=65;x2++){
                map[y2][x2]=' ';
                mvaddch(y2,x2,' ');
            }

        }
        //MAP MAKING BARIERS
        map[10][45]='|';
        mvaddch(10,45,'|');
        map[11][45]='|';
        mvaddch(11,45,'|');
        map[12][45]='|';
        mvaddch(12,45,'|');
        map[13][45]='|';
        mvaddch(13,45,'|');
        map[14][45]='|';
        mvaddch(14,45,'|');
        map[15][45]='|';
        mvaddch(15,45,'|');
        map[16][45]='|';
        mvaddch(16,45,'|');
        map[17][45]='|';
        mvaddch(17,45,'|');
        map[18][45]='|';
        mvaddch(18,45,'|');
        map[19][45]='|';
        mvaddch(19,45,'|');
        map[20][45]='|';
        mvaddch(20,45,'|');
        map[21][45]='|';
        mvaddch(21,45,'|');
        map[22][45]='|';
        mvaddch(22,45,'|');
        map[23][45]='|';
        mvaddch(23,45,'|');
        map[24][45]='|';
        mvaddch(24,45,'|');
        map[25][45]='|';
        mvaddch(25,45,'|');
        map[14][44]='-';
        mvaddch(14,44,'-');
        map[14][43]='-';
        mvaddch(14,43,'-');
        map[14][42]='-';
        mvaddch(14,42,'-');
        map[14][41]='-';
        mvaddch(14,41,'-');
        map[14][40]='-';
        mvaddch(14,40,'-');
        map[14][39]='-';
        mvaddch(14,39,'-');
        map[14][38]='-';
        mvaddch(14,38,'-');
        map[14][37]='-';
        mvaddch(14,37,'-');
        map[14][36]='-';
        mvaddch(14,36,'-');
        map[14][35]='-';
        mvaddch(14,35,'-');
        map[14][34]='-';
        mvaddch(14,34,'-');
        map[14][33]='-';
        mvaddch(14,33,'-');
        map[14][32]='-';
        mvaddch(14,32,'-');
        map[14][31]='-';
        mvaddch(14,31,'-');
        map[14][30]='|';
        mvaddch(14,30,'|');
        map[10][30]='|';
        mvaddch(10,30,'|');
        map[13][30]='|';
        mvaddch(13,30,'|');
        map[12][30]='|';
        mvaddch(12,30,'|');
        map[11][30]='|';
        mvaddch(11,30,'|');
        map[15][30]='|';
        mvaddch(15,30,'|');
        map[16][30]='|';
        mvaddch(16,30,'|');
        map[17][30]='|';
        mvaddch(17,30,'|');
        map[18][30]='|';
        mvaddch(18,30,'|');
        map[19][30]='|';
        mvaddch(19,30,'|');
        map[20][30]='|';
        mvaddch(20,30,'|');
        map[21][30]='|';
        mvaddch(21,30,'|');
        map[22][30]='|';
        mvaddch(22,30,'|');
        map[23][30]='|';
        mvaddch(23,30,'|');
        map[24][30]='|';
        mvaddch(24,30,'|');
        map[25][30]='|';
        mvaddch(25,30,'|');
        map[20][44]='-';
        mvaddch(20,44,'-');
        map[20][43]='-';
        mvaddch(20,43,'-');
        map[20][42]='-';
        mvaddch(20,42,'-');
        map[20][41]='-';
        mvaddch(20,41,'-');
        map[20][40]='-';
        mvaddch(20,40,'-');
        map[20][39]='-';
        mvaddch(20,39,'-');
        map[20][38]='-';
        mvaddch(20,38,'-');
        map[20][37]='-';
        mvaddch(20,37,'-');
        map[20][36]='-';
        mvaddch(20,36,'-');
        map[20][35]='-';
        mvaddch(20,35,'-');
        map[20][34]='-';
        mvaddch(20,34,'-');
        map[20][33]='-';
        mvaddch(20,33,'-');
        map[20][32]='-';
        mvaddch(20,32,'-');
        map[20][31]='-';
        mvaddch(20,31,'-');

        map[10][60]='|';
        mvaddch(10,60,'|');
        map[11][60]='|';
        mvaddch(11,60,'|');
        map[12][60]='|';
        mvaddch(12,60,'|');
        map[13][60]='|';
        mvaddch(13,60,'|');
        map[14][60]='|';
        mvaddch(14,60,'|');
        map[15][60]='|';
        mvaddch(15,60,'|');
        map[15][59]='-';
        mvaddch(15,59,'-');
        map[15][58]='-';
        mvaddch(15,58,'-');
        map[15][57]='-';
        mvaddch(15,57,'-');
        map[15][56]='-';
        mvaddch(15,56,'-');
        map[15][55]='-';
        mvaddch(15,55,'-');
        map[15][54]='-';
        mvaddch(15,54,'-');
        map[15][53]='|';
        mvaddch(15,53,'|');
        map[14][53]='|';
        mvaddch(14,53,'|');
        map[13][53]='|';
        mvaddch(13,53,'|');
        map[12][53]='|';
        mvaddch(12,53,'|');
        map[11][53]='|';
        mvaddch(11,53,'|');
        map[10][53]='|';
        mvaddch(10,53,'|');
        map[9][56]=' ';
        mvaddch(9,56,'_');
        map[9][55]=' ';
        mvaddch(9,55,'_');

        map[10][9]='R';
        mvaddch(10,9,'R' | COLOR_PAIR(4));
        //PORTALS
        map[bluey][bluex]=blue;
        mvaddch(bluey,bluex,blue | COLOR_PAIR(1));
        map[redy][redx]=red;
        mvaddch(redy,redx,red| COLOR_PAIR(2));
        //plate
        map[platey][platex]=plate;
        mvaddch(platey,platex,plate);
        //cube
        map[cubey][cubex]=cube;
        mvaddch(cubey,cubex,cube | COLOR_PAIR(3));
        //DOORS
        map[20][66]='-';
        mvaddch(20,66,'-');
        //win door
        if(win==true){
            map[19][66]=' ';
            mvaddch(19,66,' ');
            map[18][66]=' ';
            mvaddch(18,66,' ');
        }else{
            map[19][66]='|';
            mvaddch(19,66,'|');
            map[18][66]='|';
            mvaddch(18,66,'|');
        }
        map[17][66]='-';
        mvaddch(17,66,'-');
        //TEXT
        mvprintw(11,70," PORTAL WITHOUT RTX ");
        if(hasportalgun==false){
            mvprintw(12,70," YOU DONT HAVE PORTAL GUN ");
            //portalgun
        
            map[portalguny][portalgunx]=portalgun;
            mvaddch(portalguny,portalgunx,portalgun | COLOR_PAIR(3));
        }else{
            mvprintw(12,70," YOU HAVE PORTAL GUN ");
            if(portalgunselection==false){
                mvprintw(13,70," SELECTED BLUE ");
            }else{
                mvprintw(13,70," SELECTED RED ");
            }
            //portalgun
        
            if(temp<1){
                map[portalguny][portalgunx]=' ';
                mvaddch(portalguny,portalgunx,' ');
                temp++;
            }
        }
        
        //mvprintw(13,48," Platex: %d ",platex);
        //mvprintw(14,48," Platey: %d ",platey);
        //mvprintw(15,48," cubex: %d ",cubex);
        //mvprintw(16,48," cubey: %d ",cubey);
        //mvprintw(17,48," GAMEOVER: %d ",gameovermap1);
        mvprintw(17,70," Test Chamber 2 ");
        mvprintw(18,70," CUBE RESETS : %d ",resets);
        mvprintw(19,70," SKIP CHAMBER : ESC ");
        if (character==101&&y==9){
            mvprintw(17,48," CAKE IS A LIE ");
        }
        //MOVEMENT
        if(firstboot==false){
            mvaddch(y,x,lastchar);
            firstboot=true;
            
        }
        if(character==KEY_UP&&map[y-1][x]==' '){
            y--;
            lastchar='^';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_DOWN&&map[y+1][x]==' '){
            y++;
            lastchar='v';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_LEFT&&map[y][x-1]==' '){
            x--;
            lastchar='<';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_RIGHT&&map[y][x+1]==' '){
            x++;
            lastchar='>';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='@'&&map[y-2][x]==' '){              //moving objs
            cubey--;
            y--;
            lastchar='^';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y+1][x]=='@'&&map[y+2][x]==' '){              //moving objs
            cubey++;
            y++;
            lastchar='v';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='@'&&map[y][x-2]==' '){              //moving objs
            cubex--;
            x--;
            lastchar='<';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='@'&&map[y][x+2]==' '){              //moving objs
            cubex++;
            x++;
            lastchar='>';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_UP&&map[y-1][x]=='@'&&map[y-2][x]=='X'){              //moving objs
            cubey--;
            y--;
            lastchar='^';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y+1][x]=='@'&&map[y+2][x]=='X'){              //moving objs
            cubey++;
            y++;
            lastchar='v';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='@'&&map[y][x-2]=='X'){              //moving objs
            cubex--;
            x--;
            lastchar='<';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='@'&&map[y][x+2]=='X'){              //moving objs
            cubex++;
            x++;
            lastchar='>';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='@'&&map[y-2][x]=='O'){              //moving objs
            if(y-2==redy&&x==redx){
                if(bluey==9){
                cubey=bluey+2;
                cubex=bluex;
            }else if(bluex==9){
                cubex=bluex+2;
                cubey=bluey;
            }else if(bluey==26){
                cubey=bluey-2;
                cubex=bluex;
            }else{
                cubex=bluex-2;
                cubey=bluey;
            }
            }
            if(y-2==bluey&&x==bluex){
                if(redy==9){
                cubey=redy+2;
                cubex=redx;
            }else if(redx==9){
                cubex=redx+2;
                cubey=redy;
            }else if(redy==26){
                cubey=redy-2;
                cubex=redx;
            }else{
                cubex=redx-2;
                cubey=redy;
            }
            }
            
            y++;
            lastchar='^';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y-1][x]=='@'&&map[y-2][x]=='O'){              //moving objs
            if(y-2==redy&&x==redx){
                if(bluey==9){
                cubey=bluey+2;
                cubex=bluex;
            }else if(bluex==9){
                cubex=bluex+2;
                cubey=bluey;
            }else if(bluey==26){
                cubey=bluey-2;
                cubex=bluex;
            }else{
                cubex=bluex-2;
                cubey=bluey;
            }
            }
            if(y-2==bluey&&x==bluex){
                if(redy==9){
                cubey=redy+2;
                cubex=redx;
            }else if(redx==9){
                cubex=redx+2;
                cubey=redy;
            }else if(redy==26){
                cubey=redy-2;
                cubex=redx;
            }else{
                cubex=redx-2;
                cubey=redy;
            }
            }
            
            y++;
            lastchar='v';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='@'&&map[y][x-2]=='O'){           //moving objs
            if(y==redy&&x-2==redx){
                if(bluey==9){
                cubey=bluey+2;
                cubex=bluex;
            }else if(bluex==9){
                cubex=bluex+2;
                cubey=bluey;
            }else if(bluey==26){
                cubey=bluey-2;
                cubex=bluex;
            }else{
                cubex=bluex-2;
                cubey=bluey;
            }
            }
            if(y==bluey&&x-2==bluex){
                if(redy==9){
                cubey=redy+2;
                cubex=redx;
            }else if(redx==9){
                cubex=redx+2;
                cubey=redy;
            }else if(redy==26){
                cubey=redy-2;
                cubex=redx;
            }else{
                cubex=redx-2;
                cubey=redy;
            }
            }
            
            x--;
            lastchar='<';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='@'&&map[y][x+2]=='O'){              //moving objs
            if(y==redy&&x+2==redx){
                if(bluey==9){
                cubey=bluey+2;
                cubex=bluex;
            }else if(bluex==9){
                cubex=bluex+2;
                cubey=bluey;
            }else if(bluey==26){
                cubey=bluey-2;
                cubex=bluex;
            }else{
                cubex=bluex-2;
                cubey=bluey;
            }
            }
            if(y==bluey&&x+2==bluex){
                if(redy==9){
                cubey=redy+2;
                cubex=redx;
            }else if(redx==9){
                cubex=redx+2;
                cubey=redy;
            }else if(redy==26){
                cubey=redy-2;
                cubex=redx;
            }else{
                cubex=redx-2;
                cubey=redy;
            }
            }
            
            x++;
            lastchar='>';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='O'){              //moving objs
            if(y-1==redy&&x==redx){
                if(bluey==9){
                y=bluey+1;
                x=bluex;
            }else if(bluex==9){
                x=bluex+1;
                y=bluey;
            }else if(bluey==26){
                y=bluey-1;
                x=bluex;
            }else{
                x=bluex-1;
                y=bluey;
            }
            }
            if(y-1==bluey&&x==bluex){
                if(redy==9){
                y=redy+1;
                x=redx;
            }else if(redx==9){
                x=redx+1;
                y=redy;
            }else if(redy==26){
                y=redy-1;
                x=redx;
            }else{
                x=redx-1;
                y=redy;
            }
            }
            
            lastchar='^';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y+1][x]=='O'){  
                    //moving objs
            if(y+1==redy&&x==redx){
                if(bluey==9){
                y=bluey+1;
                x=bluex;
            }else if(bluex==9){
                x=bluex+1;
                y=bluey;
            }else if(bluey==26){
                y=bluey-1;
                x=bluex;
            }else{
                x=bluex-1;
                y=bluey;
            }
            }
            if(y+1==bluey&&x==bluex){
                
                if(redy==9){
                y=redy+1;
                x=redx;
            }else if(redx==9){
                x=redx+1;
                y=redy;
            }else if(redy==26){
                y=redy-1;
                x=redx;
            }else{
                x=redx-1;
                y=redy;
            }
            }
            
  
            lastchar='v';

            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='O'){           //moving objs
            if(y==redy&&x-1==redx){
                if(bluey==9){
                y=bluey+1;
                x=bluex;
            }else if(bluex==9){
                x=bluex+1;
                y=bluey;
            }else if(bluey==26){
                y=bluey-1;
                x=bluex;
            }else{
                x=bluex-1;
                y=bluey;
            }
            }
            if(y==bluey&&x-1==bluex){
                if(redy==9){
                y=redy+1;
                x=redx;
            }else if(redx==9){
                x=redx+1;
                y=redy;
            }else if(redy==26){
                y=redy-1;
                x=redx;
            }else{
                x=redx-1;
                y=redy;
            }
            }
            
            
            lastchar='<';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='O'){              //moving objs
            if(y==redy&&x+1==redx){
                if(bluey==9){
                y=bluey+1;
                x=bluex;
            }else if(bluex==9){
                x=bluex+1;
                y=bluey;
            }else if(bluey==26){
                y=bluey-1;
                x=bluex;
            }else{
                x=bluex-1;
                y=bluey;
            }
            }
            if(y==bluey&&x+1==bluex){
                if(redy==9){
                y=redy+1;
                x=redx;
            }else if(redx==9){
                x=redx+1;
                y=redy;
            }else if(redy==26){
                y=redy-1;
                x=redx;
            }else{
                x=redx-1;
                y=redy;
            }
            }
            
            
            lastchar='>';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='X'){
            y--;
            lastchar='^';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_DOWN&&map[y+1][x]=='X'){
            y++;
            lastchar='v';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_LEFT&&map[y][x-1]=='X'){
            x--;
            lastchar='<';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_RIGHT&&map[y][x+1]=='X'){
            x++;
            lastchar='>';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='t'){
            y--;
            lastchar='^';
            hasportalgun=true;
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_DOWN&&map[y+1][x]=='t'){
            y++;
            lastchar='v';
            hasportalgun=true;
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_LEFT&&map[y][x-1]=='t'){
            x--;
            lastchar='<';
            hasportalgun=true;
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_RIGHT&&map[y][x+1]=='t'){
            x++;
            lastchar='>';
            hasportalgun=true;
            mvaddch(y,x,lastchar);
        }else if (character==32&&hasportalgun==true){
            if(portalgunselection==false){ //BLUE
                if(lastchar=='^'){
                    bluex=x;
                    bluey=9;
                    portalgunselection=true;
                }else if(lastchar=='v'){
                    bluex=x;
                    bluey=26;
                    portalgunselection=true;
                }else if(lastchar=='<'){
                    bluex=9;
                    bluey=y;
                    portalgunselection=true;
                }else{
                    bluex=66;
                    bluey=y;
                    portalgunselection=true;
                }
            }else{
                if(lastchar=='^'){
                    redx=x;
                    redy=9;
                    portalgunselection=false;
                }else if(lastchar=='v'){
                    redx=x;
                    redy=26;
                    portalgunselection=false;
                }else if(lastchar=='<'){
                    redx=9;
                    redy=y;
                    portalgunselection=false;
                }else{
                    redx=66;
                    redy=y;
                    portalgunselection=false;
                }
            }
            mvaddch(y,x,lastchar);

        }else if (character==32&&y==9){
            mvprintw(17,48," CAKE IS A LIE ");
        }else if(character==KEY_LEFT){
            if(x==10&&y==10){
                if(cubey!=15||cubex!=15){
                    cubey=15;
                    cubex=15;
                    resets++;
                    bluex=9;
                    bluey=15;
                    redx=33;
                    redy=9;
                    y=10;
                    x=10;
                    mvprintw(16,70," CUBE RESET ");
                    mvaddch(15,15,cube| COLOR_PAIR(3));
                }
                
            }
            mvaddch(y,x,lastchar);
           
        }else{
            mvaddch(y,x,lastchar);
        }
        mvprintw(10,70," x: %d y: %d ",x,y);
        
    }while((character=getch())!=27);















     //RESETING
    resets=0;
    y=10;
    x=10;
    portalgun='t';
    portalgunx=15;
    portalguny=18;
    cube='@';
    
    plate='X';
    red='O';
    blue='O';
    bluex=9;
    bluey=14;
    redx=9;
    redy=16;
    platex=42;
    platey=12;
    cubex=22;
    cubey=12;
    temp=0;
    firstboot=false;
    lastchar='>';
    hasportalgun=false;
    portalgunselection=false; //false=blue true=red
    //bool cake=false;
    win=false;
    //MAP2
    do { 
        start_color();
        init_pair(1,COLOR_BLUE,COLOR_BLACK);
        init_pair(2,COLOR_RED,COLOR_BLACK);
        init_pair(3,COLOR_MAGENTA,COLOR_BLACK);
        init_pair(4,COLOR_CYAN,COLOR_BLACK);
        if(cubex==platex&&cubey==platey){
            win=true;
        }else{
            win=false;
        }
        if(x==51&&y==18){
            break;
        }
        if(x==51&&y==19){
            break;
        }
        
        // MAP making
        for(int y2=0;y2<=rows;y2++){
            for (int x2=0;x2<=cols;x2++){
                map[y2][x2]='#';
                mvaddch(y2,x2,'#');
            }
        }

        for(int y2=10;y2<=20;y2++){
            for (int x2=10;x2<=50;x2++){
                map[y2][x2]=' ';
                mvaddch(y2,x2,' ');
            }

        }
        //MAP MAKING BARIERS
        map[10][28]='|';
        mvaddch(10,28,'|');
        map[11][28]='|';
        mvaddch(11,28,'|');
        map[12][28]='|';
        mvaddch(12,28,'|');
        map[13][28]='|';
        mvaddch(13,28,'|');
        map[14][28]='|';
        mvaddch(14,28,'|');
        map[15][28]='|';
        mvaddch(15,28,'|');
        map[16][28]='|';
        mvaddch(16,28,'|');
        map[17][28]='|';
        mvaddch(17,28,'|');
        map[18][28]='|';
        mvaddch(18,28,'|');
        map[19][28]='|';
        mvaddch(19,28,'|');
        map[20][28]='|';
        mvaddch(20,28,'|');
        map[15][29]='-';
        mvaddch(15,29,'-');
        map[15][30]='-';
        mvaddch(15,30,'-');
        map[15][31]='-';
        mvaddch(15,31,'-');
        map[15][32]='-';
        mvaddch(15,32,'-');
        map[15][33]='-';
        mvaddch(15,33,'-');
        map[15][34]='-';
        mvaddch(15,34,'-');
        map[15][35]='-';
        mvaddch(15,35,'-');
        map[15][36]='-';
        mvaddch(15,36,'-');
        map[15][37]='-';
        mvaddch(15,37,'-');
        map[15][38]='-';
        mvaddch(15,38,'-');
        map[15][39]='-';
        mvaddch(15,39,'-');
        map[15][40]='-';
        mvaddch(15,40,'-');

        map[15][27]='-';
        mvaddch(15,27,'-');
        map[15][26]='-';
        mvaddch(15,26,'-');
        map[15][25]='-';
        mvaddch(15,25,'-');
        map[15][24]='-';
        mvaddch(15,24,'-');
        map[15][23]='-';
        mvaddch(15,23,'-');
        map[15][22]='-';
        mvaddch(15,22,'-');
        map[15][21]='-';
        mvaddch(15,21,'-');
        map[15][20]='-';
        mvaddch(15,20,'-');
        
        map[15][11]='-';
        mvaddch(15,11,'-');
        map[15][12]='-';
        mvaddch(15,12,'-');
        map[15][13]='-';
        mvaddch(15,13,'-');
        map[15][14]='-';
        mvaddch(15,14,'-');
        map[15][15]='-';
        mvaddch(15,15,'-');
        map[15][16]='-';
        mvaddch(15,16,'-');
        map[15][17]='-';
        mvaddch(15,17,'-');
        map[15][18]='-';
        mvaddch(15,18,'-');
        map[15][19]='-';
        mvaddch(15,19,'-');
        map[15][10]='-';
        mvaddch(15,10,'-');
        
        map[15][11]='-';
        mvaddch(15,41,'-');
        map[15][42]='-';
        mvaddch(15,42,'-');
        map[15][43]='-';
        mvaddch(15,43,'-');
        map[15][44]='-';
        mvaddch(15,44,'-');
        map[15][45]='-';
        mvaddch(15,45,'-');
        map[15][46]='-';
        mvaddch(15,46,'-');
        map[15][47]='-';
        mvaddch(15,47,'-');
        map[15][48]='-';
        mvaddch(15,48,'-');
        map[15][49]='-';
        mvaddch(15,49,'-');
        map[15][50]='-';
        mvaddch(15,50,'-');
        
        map[10][9]='R';
        mvaddch(10,9,'R' | COLOR_PAIR(4));
        //PORTALS
        map[bluey][bluex]=blue;
        mvaddch(bluey,bluex,blue | COLOR_PAIR(1));
        map[redy][redx]=red;
        mvaddch(redy,redx,red| COLOR_PAIR(2));
        //plate
        map[platey][platex]=plate;
        mvaddch(platey,platex,plate);
        //cube
        map[cubey][cubex]=cube;
        mvaddch(cubey,cubex,cube | COLOR_PAIR(3));
        //DOORS
        map[20][51]='-';
        mvaddch(20,51,'-');
        //win door
        if(win==true){
            map[19][51]=' ';
            mvaddch(19,51,' ');
            map[18][51]=' ';
            mvaddch(18,51,' ');
        }else{
            map[19][51]='|';
            mvaddch(19,51,'|');
            map[18][51]='|';
            mvaddch(18,51,'|');
        }
        map[17][51]='-';
        mvaddch(17,51,'-');
        //TEXT
        mvprintw(11,55," PORTAL WITHOUT RTX ");
        if(hasportalgun==false){
            mvprintw(12,55," YOU DONT HAVE PORTAL GUN ");
            //portalgun
        
            map[portalguny][portalgunx]=portalgun;
            mvaddch(portalguny,portalgunx,portalgun | COLOR_PAIR(3));
        }else{
            mvprintw(12,55," YOU HAVE PORTAL GUN ");
            if(portalgunselection==false){
                mvprintw(13,55," SELECTED BLUE ");
            }else{
                mvprintw(13,55," SELECTED RED ");
            }
            //portalgun
            
            if(temp<1){
                map[portalguny][portalgunx]=' ';
                mvaddch(portalguny,portalgunx,' ');
                temp++;
            }
            
            
        }
        
        //mvprintw(13,48," Platex: %d ",platex);
        //mvprintw(14,48," Platey: %d ",platey);
        //mvprintw(15,48," cubex: %d ",cubex);
        //mvprintw(16,48," cubey: %d ",cubey);
        //mvprintw(17,48," GAMEOVER: %d ",gameovermap1);
        mvprintw(17,55," Test Chamber 3 ");
        mvprintw(18,55," CUBE RESETS : %d ",resets);
        mvprintw(19,55," SKIP CHAMBER : ESC ");
        //MOVEMENT
        if(firstboot==false){
            mvaddch(y,x,lastchar);
            firstboot=true;
            
        }
        if(character==KEY_UP&&map[y-1][x]==' '){
            y--;
            lastchar='^';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_DOWN&&map[y+1][x]==' '){
            y++;
            lastchar='v';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_LEFT&&map[y][x-1]==' '){
            x--;
            lastchar='<';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_RIGHT&&map[y][x+1]==' '){
            x++;
            lastchar='>';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='@'&&map[y-2][x]==' '){              //moving objs
            cubey--;
            y--;
            lastchar='^';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y+1][x]=='@'&&map[y+2][x]==' '){              //moving objs
            cubey++;
            y++;
            lastchar='v';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='@'&&map[y][x-2]==' '){              //moving objs
            cubex--;
            x--;
            lastchar='<';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='@'&&map[y][x+2]==' '){              //moving objs
            cubex++;
            x++;
            lastchar='>';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_UP&&map[y-1][x]=='@'&&map[y-2][x]=='X'){              //moving objs
            cubey--;
            y--;
            lastchar='^';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y+1][x]=='@'&&map[y+2][x]=='X'){              //moving objs
            cubey++;
            y++;
            lastchar='v';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='@'&&map[y][x-2]=='X'){              //moving objs
            cubex--;
            x--;
            lastchar='<';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='@'&&map[y][x+2]=='X'){              //moving objs
            cubex++;
            x++;
            lastchar='>';
            mvaddch(cubey,cubex,cube| COLOR_PAIR(3));
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='@'&&map[y-2][x]=='O'){              //moving objs
            if(y-2==redy&&x==redx){
                if(bluey==9){
                cubey=bluey+2;
                cubex=bluex;
            }else if(bluex==9){
                cubex=bluex+2;
                cubey=bluey;
            }else if(bluey==21){
                cubey=bluey-2;
                cubex=bluex;
            }else{
                cubex=bluex-2;
                cubey=bluey;
            }
            }
            if(y-2==bluey&&x==bluex){
                if(redy==9){
                cubey=redy+2;
                cubex=redx;
            }else if(redx==9){
                cubex=redx+2;
                cubey=redy;
            }else if(redy==21){
                cubey=redy-2;
                cubex=redx;
            }else{
                cubex=redx-2;
                cubey=redy;
            }
            }
            
            y++;
            lastchar='^';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y+1][x]=='@'&&map[y+2][x]=='O'){              //moving objs
            if(y+2==redy&&x==redx){
                if(bluey==9){
                cubey=bluey+2;
                cubex=bluex;
            }else if(bluex==9){
                cubex=bluex+2;
                cubey=bluey;
            }else if(bluey==21){
                cubey=bluey-2;
                cubex=bluex;
            }else{
                cubex=bluex-2;
                cubey=bluey;
            }
            }
            if(y+2==bluey&&x==bluex){
                if(redy==9){
                cubey=redy+2;
                cubex=redx;
            }else if(redx==9){
                cubex=redx+2;
                cubey=redy;
            }else if(redy==21){
                cubey=redy-2;
                cubex=redx;
            }else{
                cubex=redx-2;
                cubey=redy;
            }
            }
            
            y++;
            lastchar='v';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='@'&&map[y][x-2]=='O'){           //moving objs
            if(y==redy&&x-2==redx){
                if(bluey==9){
                cubey=bluey+2;
                cubex=bluex;
            }else if(bluex==9){
                cubex=bluex+2;
                cubey=bluey;
            }else if(bluey==21){
                cubey=bluey-2;
                cubex=bluex;
            }else{
                cubex=bluex-2;
                cubey=bluey;
            }
            }
            if(y==bluey&&x-2==bluex){
                if(redy==9){
                cubey=redy+2;
                cubex=redx;
            }else if(redx==9){
                cubex=redx+2;
                cubey=redy;
            }else if(redy==21){
                cubey=redy-2;
                cubex=redx;
            }else{
                cubex=redx-2;
                cubey=redy;
            }
            }
            
            x--;
            lastchar='<';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='@'&&map[y][x+2]=='O'){              //moving objs
            if(y==redy&&x+2==redx){
                if(bluey==9){
                cubey=bluey+2;
                cubex=bluex;
            }else if(bluex==9){
                cubex=bluex+2;
                cubey=bluey;
            }else if(bluey==21){
                cubey=bluey-2;
                cubex=bluex;
            }else{
                cubex=bluex-2;
                cubey=bluey;
            }
            }
            if(y==bluey&&x+2==bluex){
                if(redy==9){
                cubey=redy+2;
                cubex=redx;
            }else if(redx==9){
                cubex=redx+2;
                cubey=redy;
            }else if(redy==21){
                cubey=redy-2;
                cubex=redx;
            }else{
                cubex=redx-2;
                cubey=redy;
            }
            }
            
            x++;
            lastchar='>';
            mvaddch(cubey,cubex,cube);
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='O'){              //moving objs
            if(y-1==redy&&x==redx){
                if(bluey==9){
                y=bluey+1;
                x=bluex;
            }else if(bluex==9){
                x=bluex+1;
                y=bluey;
            }else if(bluey==21){
                y=bluey-1;
                x=bluex;
            }else{
                x=bluex-1;
                y=bluey;
            }
            }
            if(y-1==bluey&&x==bluex){
                if(redy==9){
                y=redy+1;
                x=redx;
            }else if(redx==9){
                x=redx+1;
                y=redy;
            }else if(redy==21){
                y=redy-1;
                x=redx;
            }else{
                x=redx-1;
                y=redy;
            }
            }
            
            lastchar='^';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_DOWN&&map[y+1][x]=='O'){  
                    //moving objs
            if(y+1==redy&&x==redx){
                if(bluey==9){
                y=bluey+1;
                x=bluex;
            }else if(bluex==9){
                x=bluex+1;
                y=bluey;
            }else if(bluey==21){
                y=bluey-1;
                x=bluex;
            }else{
                x=bluex-1;
                y=bluey;
            }
            }
            if(y+1==bluey&&x==bluex){
                
                if(redy==9){
                y=redy+1;
                x=redx;
            }else if(redx==9){
                x=redx+1;
                y=redy;
            }else if(redy==21){
                y=redy-1;
                x=redx;
            }else{
                x=redx-1;
                y=redy;
            }
            }
            
  
            lastchar='v';

            mvaddch(y,x,lastchar);
        }else if(character==KEY_LEFT&&map[y][x-1]=='O'){           //moving objs
            if(y==redy&&x-1==redx){
                if(bluey==9){
                y=bluey+1;
                x=bluex;
            }else if(bluex==9){
                x=bluex+1;
                y=bluey;
            }else if(bluey==21){
                y=bluey-1;
                x=bluex;
            }else{
                x=bluex-1;
                y=bluey;
            }
            }
            if(y==bluey&&x-1==bluex){
                if(redy==9){
                y=redy+1;
                x=redx;
            }else if(redx==9){
                x=redx+1;
                y=redy;
            }else if(redy==21){
                y=redy-1;
                x=redx;
            }else{
                x=redx-1;
                y=redy;
            }
            }
            
            
            lastchar='<';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_RIGHT&&map[y][x+1]=='O'){              //moving objs
            if(y==redy&&x+1==redx){
                if(bluey==9){
                y=bluey+1;
                x=bluex;
            }else if(bluex==9){
                x=bluex+1;
                y=bluey;
            }else if(bluey==21){
                y=bluey-1;
                x=bluex;
            }else{
                x=bluex-1;
                y=bluey;
            }
            }
            if(y==bluey&&x+1==bluex){
                if(redy==9){
                y=redy+1;
                x=redx;
            }else if(redx==9){
                x=redx+1;
                y=redy;
            }else if(redy==21){
                y=redy-1;
                x=redx;
            }else{
                x=redx-1;
                y=redy;
            }
            }
            
            
            lastchar='>';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='X'){
            y--;
            lastchar='^';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_DOWN&&map[y+1][x]=='X'){
            y++;
            lastchar='v';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_LEFT&&map[y][x-1]=='X'){
            x--;
            lastchar='<';
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_RIGHT&&map[y][x+1]=='X'){
            x++;
            lastchar='>';
            mvaddch(y,x,lastchar);
        }else if(character==KEY_UP&&map[y-1][x]=='t'){
            y--;
            lastchar='^';
            hasportalgun=true;
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_DOWN&&map[y+1][x]=='t'){
            y++;
            lastchar='v';
            hasportalgun=true;
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_LEFT&&map[y][x-1]=='t'){
            x--;
            lastchar='<';
            hasportalgun=true;
            mvaddch(y,x,lastchar);
        }
        else if(character==KEY_RIGHT&&map[y][x+1]=='t'){
            x++;
            lastchar='>';
            hasportalgun=true;
            mvaddch(y,x,lastchar);
        }else if (character==32&&hasportalgun==true){
            if(portalgunselection==false){ //BLUE
                if(lastchar=='^'){
                    bluex=x;
                    bluey=9;
                    portalgunselection=true;
                }else if(lastchar=='v'){
                    bluex=x;
                    bluey=21;
                    portalgunselection=true;
                }else if(lastchar=='<'){
                    bluex=9;
                    bluey=y;
                    portalgunselection=true;
                }else{
                    bluex=51;
                    bluey=y;
                    portalgunselection=true;
                }
            }else{
                if(lastchar=='^'){
                    redx=x;
                    redy=9;
                    portalgunselection=false;
                }else if(lastchar=='v'){
                    redx=x;
                    redy=21;
                    portalgunselection=false;
                }else if(lastchar=='<'){
                    redx=9;
                    redy=y;
                    portalgunselection=false;
                }else{
                    redx=51;
                    redy=y;
                    portalgunselection=false;
                }
            }
            mvaddch(y,x,lastchar);

        }else if(character==KEY_LEFT){
            if(x==10&&y==10){
                if(cubey!=15||cubex!=15){
                    cubey=15;
                    cubex=15;
                    resets++;
                    bluex=9;
                    bluey=15;
                    redx=33;
                    redy=9;
                    y=10;
                    x=10;
                    mvprintw(16,55," CUBE RESET ");
                    mvaddch(15,15,cube| COLOR_PAIR(3));
                }
                
            }
            mvaddch(y,x,lastchar);
           
        }else{
            mvaddch(y,x,lastchar);
        }
        mvprintw(10,55," x: %d y: %d ",x,y);
        
    }while((character=getch())!=27);
    refresh();  

    getch();  
    endwin();
    
    return 0;
}
