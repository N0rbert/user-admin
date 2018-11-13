/*   mate-user-admin 
*   Copyright (C) 2018  zhuyaliang https://github.com/zhuyaliang/
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.

*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.

*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __USER_H__
#define __USER_H__

#include <gtk/gtk.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <sys/time.h>
#define MATE_DESKTOP_USE_UNSTABLE_API
#include <mate-desktop-2.0/libmate-desktop/mate-languages.h>
#include <mate-desktop-2.0/libmate-desktop/mate-desktop-thumbnail.h>

#include <accountsservice-1.0/act/act-user-manager.h>
#include <accountsservice-1.0/act/act-user.h>
#include <libintl.h> // gettext 库支持  
#include <locale.h> // 本地化locale的翻译支持  

#define  DEFAULT    "/usr/share/mate-user-admin/face/Default.png"
#define  NUMMAX    20
#define  PICMAX    20    
#define  NONE      3

#define  OLDPASS   0
#define  NEWPASS   1

#define  STANDARD  0
#define  ADMIN     1
#define _(STRING)  gettext(STRING)   
#define PACKAGE    "mate-user-admin"   
#define LOCALEDIR  "/usr/share/locale/" 

enum
{
    COL_USER_FACE= 0,
    INT_COLUMN,
    LIST_TEXT ,
    LIST_COLOR,
    LIST_FRONT,
    N_COLUMNS
};
/*用户属性结构体*/

typedef  struct
{
    char        UserName[48];   //user name
    char        RealName[48];   //real name
    char        HomeName[48];   //user home directory
    char        UserIcon[128];  //user icon path
    char        UserType;       //user type admin or standard
    char        LangName[48];       //language type temporary support for English and Chinese
    int         PasswordType;   //passwod type 
    char        PassText[48];   //user login password
    gboolean    LoginType;      //user automatic logon
    char        UserTime[48];   //user login time
    GtkTreeIter Iter;           //user list iter
    ActUser     *User;         
}UserInfoList;    
typedef struct 
{
    UserInfoList     ul[NUMMAX];
    GtkWidget        *MainWindow;
    GtkWidget        *IconWindow;
    GtkWidget        *PassWindow;
    GtkWidget        *AddUserWindow;
    GtkTreeModel     *Model;
    GtkTreeSelection *UserSelect;
    GtkWidget        *UserList;
    GtkListStore     *ListSTore;
    GtkWidget        *ButtonFace;
    GtkWidget        *EntryName;
    GtkWidget        *ComUserType;
    GtkWidget        *ComUserLanguage;
    GtkWidget        *ButtonPass;
    GtkWidget        *SwitchAutoLogin;
    GtkWidget        *ButtonUserTime;
    GtkWidget        *NewPassEntry;
    GtkWidget        *OldPassEntry;
    GtkWidget        *LabelPassNote;
    GtkWidget        *LevelBar;
    GtkWidget        *ButtonConfirm;
    GtkWidget        *CheckPassEntry;
    GtkWidget        *LabelSpace;
    GtkWidget        *RealNameEntry;
    GtkWidget        *UserNameEntry;
    GtkWidget        *LabelNameNote;
    GtkWidget        *NewUserType;
    GtkWidget        *NewUserLangType;
    GtkWidget        *RadioButton1;
    GtkWidget        *RadioButton2;
    GtkWidget        *CropArea;
    int               UserCount;    //Valid user number
    int               CheckPassTimeId;//Check the password format timer
    int               CheckNameTimeId; //Check the Realname format timer
    int               MouseId;
    int               KeyId;
    char              TmpPass[24];
}UserAdmin;
int gnCnt;                //计数
int gnCurrentUserIndex;   //代表当前用户标号
GtkWidget *WindowLogin;          //首页窗口
char **all_languages;
GHashTable *LocaleHash;
GSList     *LangList;
#endif
