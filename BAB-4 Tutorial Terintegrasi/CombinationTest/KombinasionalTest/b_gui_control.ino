// Variable GUI
int gui_pageNow=0;
int gui_menuSelect=3;

void bt_allscan(){
  bt_scan(pin_BtDown,1);
  bt_scan(pin_BtUp,2);
  bt_scan(pin_BtBack,3);
  bt_scan(pin_BtEnter,4);
}

void gui_cur_erase(){
  lcd_erase(0, 0);
  lcd_erase(0, 1);
}

void gui_control(){
  switch(gui_pageNow){
    case 0:
      gui_changePage();
      gui_cursorpos(gui_menuSelect);
      break;

    case 99:
      if(btn_trig[4]==pressed){
        gui_pageNow=1; gui_changePage(); gui_menuSelect=0; gui_cursorpos(gui_menuSelect);
      }
    break;

    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
      if(btn_trig[1]==pressed){
        gui_menuSelect++; gui_cur_erase();
        if(gui_menuSelect>1){
          gui_menuSelect=0;
          gui_pageNow++; 
          if(gui_pageNow>8){
            gui_pageNow=0;
          }
          gui_changePage();
          gui_cursorpos(gui_menuSelect);
        }
        else{gui_cursorpos(gui_menuSelect);}
      }
      else if(btn_trig[2]==pressed){
        gui_menuSelect--; gui_cur_erase();
        if(gui_menuSelect<0){
          gui_menuSelect=1;
          gui_pageNow--;
          if(gui_pageNow<0){
            gui_pageNow=8;
          }
          gui_changePage();
          gui_cursorpos(gui_menuSelect);
        }
        else{gui_cursorpos(gui_menuSelect);}
      }
      if(btn_trig[4]==pressed){
        if(gui_menuSelect==0){
          gui_menuSelect=1;
          gui_pageNow+=10;
          gui_changePage(); 
          gui_cursorpos(gui_menuSelect);
        }
        else if(gui_menuSelect==1){
          gui_menuSelect=1;
          gui_pageNow+=20;
          gui_changePage(); 
          gui_cursorpos(gui_menuSelect);
        }
      }
    break;
  }
}