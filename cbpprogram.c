#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>
char stbs[20],stbd[20],temp_s[20];//stbs means song to be searched , temp_s are strings used in search function//
char recently_played[100][20];//it is a stack which will store the recently played songs//
int recent=-1;//in recently_played stack instead of top we are using recent named int variable//
int front=-1,rear=-1;
char queue[100][20];
struct dor// it is substructure corresponding to date of releas//
{
    int date;
    int month;
    int year;
};

struct song //it is the main structure of each song//
{
    char title[40];
    char artist[40];
    char language[40];
    char gener[40];
    char album[40];
    struct dor release_date;
    struct song *next;
    struct song *prev;
}*first,*last,*temp,*play,*tempd;

void printMusicPlayerPattern();
struct song *playlist()//this function creates nodes and all these are linked in doubly fashion which creates a playlist environment//
{
    struct song *s1 = malloc(sizeof(struct song));//song1
    s1->release_date.date = 17;
    s1->release_date.month = 7;
    s1->release_date.year = 2022;
    strcpy(s1->title, "Kesariya");
    strcpy(s1->artist, "Arijith singh");
    strcpy(s1->language, "Hindi");
    strcpy(s1->gener, "Love");
    strcpy(s1->album, "Bramhastra");
    s1->prev=NULL;
    s1->next=NULL;
    first=s1;
    last=s1;

    struct song *s2 = malloc(sizeof(struct song));//song2
    s2->release_date.date = 6;
    s2->release_date.month = 1;
    s2->release_date.year = 2017;
    strcpy(s2->title, "Shape_of_you");
    strcpy(s2->artist, "Ed_sheeran");
    strcpy(s2->language, "English");
    strcpy(s2->gener, "Pop");
    strcpy(s2->album, "Divide");
   s1->next=s2;
    s2->prev=s1;
    s2->next=NULL;
    last=last->next;

    struct song *s3 = malloc(sizeof(struct song));//song3
    s3->release_date.date = 10;
    s3->release_date.month = 11;
    s3->release_date.year = 2022;
    strcpy(s3->title, "Mastaaru");
    strcpy(s3->artist, "shwetha _mohan");
    strcpy(s3->language, "Telugu");
    strcpy(s3->gener, "Love");
    strcpy(s3->album, "Sir");
   s2->next=s3;
    s3->prev=s2;
    s3->next=NULL;
    last=last->next;

    struct song *s4 = malloc(sizeof(struct song));//song4
    s4->release_date.date = 25;
    s4->release_date.month = 10;
    s4->release_date.year = 2021;
    strcpy(s4->title, "Darshana");
    strcpy(s4->artist, "Hesham");
    strcpy(s4->language, "Malyalam");
    strcpy(s4->gener, "Romance");
    strcpy(s4->album, "Hridayam");
   s3->next=s4;
    s4->prev=s3;
    s4->next=NULL;
    last=last->next;
   
     struct song *s5 = malloc(sizeof(struct song)); //song5
    s5->release_date.date = 12;
    s5->release_date.month = 1;
    s5->release_date.year = 2017;
    strcpy(s5->title, "Despacito");
    strcpy(s5->artist, "luis_fonsi");
    strcpy(s5->language, "Spanish");
    strcpy(s5->gener, "latin_hip_hop");
    strcpy(s5->album, "Noisematch");
   s4->next=s5;
    s5->prev=s4;
    s5->next=NULL;
    last=last->next;
    
     struct song *s6= malloc(sizeof(struct song)); //song6
    s6->release_date.date = 01;
    s6->release_date.month = 04;
    s6->release_date.year = 2023;
    strcpy(s6->title, "Nijamene_chebuthunna");
    strcpy(s6->artist, "sid_sriram");
    strcpy(s6->language, "telugu");
    strcpy(s6->gener, "love");
    strcpy(s6->album, "Ooru_peru_bhairavakona");
   s5->next=s6;
    s6->prev=s5;
    s6->next=NULL;
    last=last->next;
    
         struct song *s7= malloc(sizeof(struct song)); //song7
    s7->release_date.date = 06;
    s7->release_date.month = 06;
    s7->release_date.year = 2023;
    strcpy(s7->title, "Tere_vaaste");
    strcpy(s7->artist, "Sachin_Jigar");
    strcpy(s7->language, "Hindi");
    strcpy(s7->gener, "Romance");
    strcpy(s7->album, "Zara_hatke_zara_bachke");
   s6->next=s7;
    s7->prev=s6;
    s7->next=NULL;
    last=last->next;
    
         struct song *s8= malloc(sizeof(struct song)); //song8
    s8->release_date.date = 15;
    s8->release_date.month = 03;
    s8->release_date.year = 2019;
    strcpy(s8->title, "Teri_Mitti");
    strcpy(s8->artist, "B_praak");
    strcpy(s8->language, "Hindi");
    strcpy(s8->gener, "Patriotic");
    strcpy(s8->album, "Kesari");
   s7->next=s8;
    s8->prev=s7;
    s8->next=NULL;
    last=last->next;
    
	printf("\n\n");
	printf("\t\t\t\t\t    <-PLAYLIST SONGS->\n\n");
   temp=first;
   while(temp!=NULL)
   {
   	printf("\t\t\t\t\t\t%s\n",temp->title);
   	temp=temp->next;
	} 
    return first;
}

struct song *add_song_e()//it useful to add a song at end to our playlist 
{	
	printf("\n\n");
	printf("\t\t\t\t\t\t<-ADD SONG->\\n\n");
	struct song *as=malloc(sizeof(struct song));

	printf("\t\t\t\t\t\ttitle : ");
	fflush(stdin);gets(as->title);
	printf("\t\t\t\t\t\tartist : ");
	fflush(stdin);	gets(as->artist);
	printf("\t\t\t\t\t\tlanguage : ");
	fflush(stdin);gets(as->language);                                                            //here we used gets instead of scanf because it is terminating as it encounter " " (space)//
	printf("\t\t\t\t\t\tgenre : ");
	fflush(stdin);gets(as->gener);
	printf("\t\t\t\t\t\talbum : ");
	fflush(stdin);gets(as->album);
	printf("\t\t\t\t\t\tdate month year : ");
	scanf("%d %d %d",& as->release_date.date ,& as->release_date.month,& as->release_date.year);
	last->next=as;
	as->prev=last;
	as->next=NULL;
	last=as;
	printf("\n\t\t\t\t\t\tsong  %s added\n",last->title);
	return first;
}
void new_songs()//this function is to sort our playlist such that they are in descending order of release date of hte song// 
{
    struct song *pass, *ptr;
    struct song *temp_sort = NULL;
    int swapped;

    if (first == NULL)
    {
        printf("No songs found.\n");
        return;
    }

    do
    {
        swapped = 0;
        pass = first;

        while (pass->next != temp_sort)
        {
            ptr = pass->next;

            if (ptr->release_date.year > pass->release_date.year ||
                (ptr->release_date.year == pass->release_date.year && ptr->release_date.month > pass->release_date.month) ||
                (ptr->release_date.year == pass->release_date.year && ptr->release_date.month == pass->release_date.month && ptr->release_date.date > pass->release_date.date))
            {
                // Swap songs
                struct song *temp_next = ptr->next;
                struct song *temp_prev = pass->prev;

                if (temp_prev != NULL)
                    temp_prev->next = ptr;
                else
                    first = ptr;

                if (temp_next != NULL)
                    temp_next->prev = pass;

                pass->next = temp_next;
                pass->prev = ptr;
                ptr->next = pass;
                ptr->prev = temp_prev;

                pass = ptr;
                swapped = 1;
            }

            pass = pass->next;
        }

        temp_sort = pass;
    } while (swapped);
printf("\n\n");
    printf("\t\t\t\t\t\t<<-NEW SONGS->>\n\n");

    temp = first;
    while (temp != NULL)
    {
        printf("\t\t\t\t\t\t%s\t%d %d %d\t\n", temp->title, temp->release_date.date, temp->release_date.month, temp->release_date.year);
        temp = temp->next;
    }
}

void alpha_song()//this function is to sort our playlist alphabetically according to title of the song//
{
	 struct song *pass, *ptr;
    struct song *temp_sort = NULL;
    int swapped;

    if (first == NULL)
    {
        printf("\t\t\t\t\t\tNo songs found.\n");
        return;
    }

    do
    {
        swapped = 0;
        pass = first;

        while (pass->next != temp_sort)
        {
            ptr = pass->next;

            if ( strcasecmp(ptr->title , pass->title) < 0)
            {
                // Swap songs
                struct song *temp_next = ptr->next;
                struct song *temp_prev = pass->prev;

                if (temp_prev != NULL)
                    temp_prev->next = ptr;
                else
                    first = ptr;

                if (temp_next != NULL)
                    temp_next->prev = pass;

                pass->next = temp_next;
                pass->prev = ptr;
                ptr->next = pass;
                ptr->prev = temp_prev;

                pass = ptr;
                swapped = 1;
            }

            pass = pass->next;
        }

        temp_sort = pass;
    } while (swapped);
	printf("\n\n");
    printf("\t\t\t\t\t\t<<-TITLES->>\n\n");

    temp = first;
    while (temp != NULL)
    {
        printf("\t\t\t\t\t\t%s\n",temp->title);
        temp = temp->next;
    }
}

void e_basha()//this function is to sort the playlist alphabetically according to language of the song//
{
	struct song *pass, *ptr;
    struct song *temp_sort = NULL;
    int swapped;

    if (first == NULL)
    {
        printf("No songs found.\n");
        return;
    }

    do
    {
        swapped = 0;
        pass = first;

        while (pass->next != temp_sort)
        {
            ptr = pass->next;

            if ( strcasecmp(ptr->language , pass->language) < 0)
            {
                // Swap songs
                struct song *temp_next = ptr->next;
                struct song *temp_prev = pass->prev;

                if (temp_prev != NULL)
                    temp_prev->next = ptr;
                else
                    first = ptr;

                if (temp_next != NULL)
                    temp_next->prev = pass;

                pass->next = temp_next;
                pass->prev = ptr;
                ptr->next = pass;
                ptr->prev = temp_prev;

                pass = ptr;
                swapped = 1;
            }

            pass = pass->next;
        }

        temp_sort = pass;
    } while (swapped);
	printf("\n\n");
    printf("\t\t\t\t\t\t<<-LANGUAGES->>\n\n");

    temp = first;
    while (temp != NULL)
    {
        printf("\t\t\t\t\t\t%s\t%s\n",temp->title,temp->language);
        temp = temp->next;
    }
}

void artist()//this function is to sort the playlist alphabetically according to language of the song//
{
	struct song *pass, *ptr;
    struct song *temp_sort = NULL;
    int swapped;

    if (first == NULL)
    {
        printf("No songs found.\n");
        return;
    }

    do
    {
        swapped = 0;
        pass = first;

        while (pass->next != temp_sort)
        {
            ptr = pass->next;

            if ( strcasecmp(ptr->artist , pass->artist) < 0)
            {
                // Swap songs
                struct song *temp_next = ptr->next;
                struct song *temp_prev = pass->prev;

                if (temp_prev != NULL)
                    temp_prev->next = ptr;
                else
                    first = ptr;

                if (temp_next != NULL)
                    temp_next->prev = pass;

                pass->next = temp_next;
                pass->prev = ptr;
                ptr->next = pass;
                ptr->prev = temp_prev;

                pass = ptr;
                swapped = 1;
            }

            pass = pass->next;
        }

        temp_sort = pass;
    } while (swapped);
	printf("\n\n");
    printf("\t\t\t\t\t\t<<-ARTISTS->>\n\n");

    temp = first;
    while (temp != NULL)
    {
        printf("\t\t\t\t\t\t%s\t%s\n",temp->title,temp->artist);
        temp = temp->next;
    }
}

void genre()//this function is to sort playlist alphabetically according to genre of the song//
{
		struct song *pass, *ptr;
    struct song *temp_sort = NULL;
    int swapped;

    if (first == NULL)
    {
        printf("No songs found.\n");
        return;
    }

    do
    {
        swapped = 0;
        pass = first;

        while (pass->next != temp_sort)
        {
            ptr = pass->next;

            if ( strcasecmp(ptr->gener , pass->gener) < 0)
            {
                // Swap songs
                struct song *temp_next = ptr->next;
                struct song *temp_prev = pass->prev;

                if (temp_prev != NULL)
                    temp_prev->next = ptr;
                else
                    first = ptr;

                if (temp_next != NULL)
                    temp_next->prev = pass;

                pass->next = temp_next;
                pass->prev = ptr;
                ptr->next = pass;
                ptr->prev = temp_prev;

                pass = ptr;
                swapped = 1;
            }

            pass = pass->next;
        }

        temp_sort = pass;
    } while (swapped);
	printf("\n\n");
    printf("\t\t\t\t\t\t<<-GENRE->>\n\n");

    temp = first;
    while (temp != NULL)
    {
        printf("\t\t\t\t\t\t%s\t%s\n",temp->title,temp->gener);
        temp = temp->next;
    }
}

void album()//this function is to sort playlist alphabeticslly according to album of song
{
		struct song *pass, *ptr;
    struct song *temp_sort = NULL;
    int swapped;

    if (first == NULL)
    {
        printf("No songs found.\n");
        return;
    }

    do
    {
        swapped = 0;
        pass = first;

        while (pass->next != temp_sort)
        {
            ptr = pass->next;

            if ( strcasecmp(ptr->album , pass->album) < 0)
            {
                // Swap songs
                struct song *temp_next = ptr->next;
                struct song *temp_prev = pass->prev;

                if (temp_prev != NULL)
                    temp_prev->next = ptr;
                else
                    first = ptr;

                if (temp_next != NULL)
                    temp_next->prev = pass;

                pass->next = temp_next;
                pass->prev = ptr;
                ptr->next = pass;
                ptr->prev = temp_prev;

                pass = ptr;
                swapped = 1;
            }

            pass = pass->next;
        }

        temp_sort = pass;
    } while (swapped);
	printf("\n\n");
    printf("\t\t\t\t\t\t<<-ALBUM->>\n\n");

    temp = first;
    while (temp != NULL)
    {
        printf("\t\t\t\t\t\t%s     %s\n",temp->album,temp->title);
        temp = temp->next;
    }
}

void recently_added()//this function is to sort our playlist according to recently added to playlist//
{
	struct song *current,*prev=NULL,*tempr;
	current=first;
	while(current!=NULL)
	{
		tempr=current->next;
		current->next=prev;
		current->prev=tempr;
		prev=current;
		current=tempr;
	}
	tempr=first; //}changing 
  	first=prev;  //}first and last pointers
	last=temp;   //}of our playlist
	printf("\n\n");
	printf("\t\t\t\t\t\t<-RECENTLY ADDED->\n\n");
	temp=first;
	while(temp!=NULL)
	{
		printf("\t\t\t\t\t\t%s\n",temp->title);
		temp=temp->next;
	}
}

int search_song()//this function is to search for a song in playlist//
{
	printf("\n\n");
	printf("\t\t\t\t\t\t???????????????????????????\n");
	printf("\t\t\t\t\t\t??  Q search             ??\n");
	printf("\t\t\t\t\t\t???????????????????????????\n");
	printf("\n\n");
	char stbs[100]; // Declare stbs as a character array
	fflush(stdin);
	printf("\t\t\t\t\t\tsong:");
	scanf("\t\t\t\t\t\t%s", stbs); // Remove the '&' operator before stbs
	temp = first;
	strcpy(temp_s, temp->title);
	while ((strcasecmp(temp_s, stbs) != 0) && (temp != NULL)) // Change the || operator to &&
	{
		temp = temp->next;
		if (temp != NULL)
			strcpy(temp_s, temp->title);
	}
	if (strcasecmp(temp_s, stbs) == 0) //NOTE:this line is code to compare the song to be searched (which is not case sensitive as we are using *STRCASECMP*)//
	{
		printf("\t\t\t\t\t\tSong found\n"); 
		return 1;
	}
	else
	{
		printf("\t\t\t\t\t\tsong not found\n");	
		return 0;
	}
}
void play_song()//this function will play the song //
{ int result;
	printf("\n\t\t\t\t\t\t<-PLAY SONG->");
  result=search_song();//NOTE:here SEARCH function is called so that user first search the song if he find it he will play it//
  play=temp;
  if(result==1)
  { printf("\n\n");
  	printf("\t\t\t\t\t\tPlaying...\n");
  	printf("\t\t\t\t\t\t%s\n",play->title);
  	strcpy(recently_played[++recent],play->title);//NOTE:as the above song is played ,it is pushed to an stack named recently_played //
  	printf("\t\t\t\t\t\t<- (21)\t(22) ->\n");
  }
  else 
  { printf("\n\n");
  	printf("\t\t\t\t\t\tCan't play that one \n");
  }
}
  
void display_titles()//This function will display all the songs in our playlist//
{
	printf("\n\n");
	printf("\t\t\t\t\t\t<-PLAYLIST SONGS->\n\n");
	temp=first;
	while(temp!=NULL)
	{
		printf("\t\t\t\t\t\t%s\n",temp->title);
		temp=temp->next;
	}
  }
  
  void backward()//this is the option through which user can traverse in *BACKWARD* direction one by one//
  {	printf("\n\n");
  	if(play->prev==NULL)// if the play pointer points to the very first song then we can't traverse further backward //
  	{
  		printf("\t\t\t\t\t\treplaying..\n");//NOTE:hence we are replaying the first song itself :) //
  		printf("\t\t\t\t\t\t%s\n",play->title);
  		printf("\t\t\t\t\t\t<- (21)\t(22) ->\n");
	  }
	else
	{	
		play=play->prev;
		printf("\t\t\t\t\t\tplaying..\n");
		printf("\t\t\t\t\t\t%s\n",play->title);
		strcpy(recently_played[++recent],play->title);//as the above song is played ,it is pushed to an stack named recently_played // 
		printf("\t\t\t\t\t\t<- (21)\t(22) ->\n");
	  }  
	}  
void forward()//this is the option through which user can traverse and also play song in *FORWARD* direction one by one//
{	printf("\n\n");
	if(play->next==NULL)//if the play pointer points to the laaast song the obviuosly we cant traverse forward //
	{
		printf("\t\t\t\t\t\treplaying..\n");//hence we are playing the laaast song again//
		printf("\t\t\t\t\t\t%s\n",play->title);
  		printf("\t\t\t\t\t\t<- (21)\t(22) ->\n");	
	}
	else
	{
		play=play->next;
		printf("\t\t\t\t\t\tplaying..\n");
		printf("\t\t\t\t\t\t%s\n",play->title);
		strcpy(recently_played[++recent],play->title);//as the above song is played ,it is pushed to an stack named recently_played //
		printf("\t\t\t\t\t\t<- (21)\t(22) ->\n");
	}
}

void display_recently_played()//it displays all recently listened song sequentially//
{
	int itd=recent;
	printf("\n\n");
	printf("\t\t\t\t\t\t<-RECENTLY PLAYED->\n\n");
	
	if(itd!=-1){
		while(itd!=-1)
	{
		printf("\t\t\t\t\t\t%s\n",recently_played[itd]);
		itd--;
	}
	}
	else printf("\t\t\t\t\t\tno songs played yet\n");
}

void  play_recently_played_songs()//this function helps us to play recently played song again//
{
printf("\n\n");
if(recent>=0)
{
	printf("\t\t\t\t\t\tplaying..\n");
	printf("\t\t\t\t\t\t%s\n",recently_played[recent--]);//NOTE:here the song will be played a simultaneously will be removed from the stack ie.,recently_played//
	printf("\t\t\t\t\t\t  ->  (10)\n");
	}
	else 
	printf("\t\t\t\t\t\tNo recent songs\n");	
}

void circular_fashion()// this function helps us to play songs in circular loop fashion
{
	first->prev=last;
	last->next=first;
	printf("\n\n\t\t\t\t\t\t<-CIRCULAR LOOP ON->\n");
	 play_song();
}

                                                          //QUEUES//
void add_songs_to_queue() //function no 11
{	printf("\n\t\t\t\t\t<-add song to queue->");
	if(search_song()){
			
	//	getchar();
		if(front==-1 && rear==-1){
			front++;
			rear++;
		}
		strcpy(queue[rear++],temp->title);
	
		printf("\t\t\t\t\t\tto continue press (11)\n");
	}
	else {
		printf("\t\t\t\t\t\tno song found\n");
		printf("\t\t\t\t\t\tto continue press (11)\n");
	}
}

void play_queue_songs()   //function no 13
{
	if(rear!=-1 && front!=-1 && front<rear){
		printf("\t\t\t\t\t\tPlaying..\n\n");
		printf("\t\t\t\t\t\t%s\n",queue[front++]);
		printf("\t\t\t\t\t\tnext in queue press (13)\n");
	}
	else{
		front=-1;
		rear=-1;
		printf("\t\t\t\t\t\toops.. no songs in queue currently\n");
	}
}

void display_queue_songs()  //function no 13
{
if(rear!=-1 && front!=-1){
		printf("\t\t\t\t\t\tsongs in queue: \n\n");
	int i;
	for(i=front;i<=rear;i++){
		printf("\t\t\t\t\t\t%s\n",queue[i]);
	}
}
	else {
		printf("\t\t\t\t\t\tno songs to display\n");
	}
}

void delete_song(){
	printf("\n\t\t\t\t\t\t<-DELETE SONG->\n");
	int ans=search_song();
	if(ans)
	{ 
		strcpy(stbd,temp->title);
		if(strcasecmp(stbd,first->title) == 0){
		tempd=first;
		first=first->next;
		first->prev=NULL;
		free(tempd);
	}
	else if(strcasecmp(stbd,last->title) == 0){
		tempd=last;
		last=last->prev;
		last->next=NULL;
		free(tempd);
	}
	else{
		temp=first;
		while(strcasecmp(temp->next->title,stbd) !=0  && temp!=NULL){
			temp=temp->next;
		}
	
			temp->next=temp->next->next;
		temp->next->prev=temp;
	}
	printf("\t\t\t\t\t\tsong %s deleted\n",stbd);
	}	
}

int main()
{ 	int result,choice=1;	
    printMusicPlayerPattern();
    playlist();
    printf("\n\n(1)-> PLAY\n(2)->SONGS\n(3)->ADD SONG\n(4)->DELETE SONG\n(5)->RECENTS\n(6)->QUEUE\n(7)->PLAY IN LOOP\n(8)->SORT\n(23)->OPTIONS\n");
	 while(choice>0 && choice<24)//NOTE:choice<NUMBER, here the NUMBER-1 represents total number of functions in main function. so always update it as u add a function to main :) //
 {
   	    	printf("\n\n\t\t\t\t\t\tchoice:");
	scanf("\t\t\t\t\t\t%d",&choice);
	switch(choice)
	{
		                            //GENERAL OPTIONS WITH LINKED LIST(PLAYLIST)//
		                            
    case 1:play_song();break;
    case 2:display_titles();break;
    case 3:add_song_e();break;
    case 4:delete_song();break;
    case 5:printf("\n\n\t\t\t\t\t\t(9)->VIEW RECENTS\n\t\t\t\t\t\t(10)->PLAY RECENTLY PLAYED\n");break;
    case 6:printf("\n\n\t\t\t\t\t\t(11)->ADD TO QUEUE\n\t\t\t\t\t\t(12)->SONGS IN QUEUE\n\t\t\t\t\t\t(13)->PLAY QUEUE\n");break;
    case 7:circular_fashion();break;
    case 8:printf("\n\nSORT BY..\n(14)->TITLE\n(15)->ARTIST\n(16)->RECENT RELEASE\n(17)->RECENTLY ADDED\n(18)->LANGUAGE\n(19)->GENRE\n(20)->ALBUM\n");
	       break;         
			 
			                       //STACK DATA STRUCTURE//  
	case 9:display_recently_played();break;
    case 10:play_recently_played_songs();break;
    
    
                                  //QUEUE DATA STRUCTURE//
	case 11:add_songs_to_queue();break;
    case 12:display_queue_songs();break;
    case 13:play_queue_songs();break;
    
    
                                 //SORTINGS//
	case 14:alpha_song();break;
    case 15:artist();break;
    case 16:new_songs();break;
    case 17:recently_added();break;
    case 18:e_basha();break;
    case 19:genre();break;
    case 20:album();break;
    
    
    							//PLAYLIST TRAVERSALS//
    case 21:backward();break;
    case 22:forward();break;
    case 23:printf("\n\n(1)-> PLAY\n(2)->SONGS\n(3)->ADD SONG\n(4)->DELETE SONG\n(5)->RECENTS\n(6)->QUEUE\n(7)->PLAY IN LOOP\n(8)->SORT\n(23)->OPTIONS\n");

    
    //case 2:search_song();break;
    default:choice=1;break;
    }
  }
    return 0;
}
void printMusicPlayerPattern()// this funcion is heading of our project//
 {
            printf("\t\t **  **  *  *   ***  *****   ***     ****   *        *    *   *  *****  ****  \n");
            printf("\t\t * *  *  *  *  *       *    *        *   *  *       * *   *   *  *      *   * \n");
            printf("\t\t * *  *  *  *   **     *    *        ****   *      *****   ***   ****   ****  \n");
            printf("\t\t *    *  *  *     *    *    *        *      *      *   *    *    *      *  *  \n");
            printf("\t\t *    *  ****  ***   *****   ***     *      *****  *   *    *    *****  *   * \n");
}