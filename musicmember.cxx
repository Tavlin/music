#include "musicmember.h"


using namespace std;

/*******************************************************************************
normal constructor for the class Musicmember
*******************************************************************************/
Musicmember::Musicmember(string a, vector<string> b, string c, vector<song> d){
  bandname = a;
  genres = b;
  bandinfo = c;
  songlist = d;
}

/*******************************************************************************
init for the song structure
*******************************************************************************/
song song_init(string songname, string songinfo, string album, string spotifylink, string youtubelink, bool prio){
  song new_song;

  new_song.songname = songname;
  new_song.songinfo = songinfo;
  new_song.album = album;
  new_song.spotifylink = spotifylink;
  new_song.youtubelink = youtubelink;
  new_song.prio = prio;

  return new_song;
}

/*******************************************************************************
function to search for a certain genres
*******************************************************************************/
void search_genre(vector<Musicmember> list, string searched_genre)
{
  int size_list = list.size();
  int size_genres = 0;
  for (int i = 0; i < size_list; i++)
  {
    size_genres = list[i].genres.size();
    for (int j = 0; j < size_genres; j++)
    {
      if(list[i].genres[j].compare(searched_genre) == 0)
      {
        list[i].PrintMusicmember();
      }
    }
  }
}
/*******************************************************************************
function to print out all possible commands in the shell to the user.
*******************************************************************************/
void print_commands(){
  cout << "type: \"genre\" to search for a specific genre." << endl;
  cout << "type: \"band\" to search for a band." << endl;
  cout << "type: \"song\" to search for a specific song." << endl;
  cout << "type: \"album\" to search for a specific album." << endl << endl;
};


vector<Musicmember> new_list(){

  vector<Musicmember> newlist;

  string input;
  string bandname;
  string new_genre;
  string new_bandinfo;
  int number_new_genres;
  int genre_size = 0;
  vector<string> genres;
  string bandinfo;
  vector<song> songlist;

  // start of a new musiclist with bandname input
  cout << "Please enter the bandname: ";
  cin >> bandname;

  // followed by one or more genre(s)
  cout << endl << "Now enter ONE genre of the band: ";
  cin >> new_genre;
  genres = {new_genre};
  cout << "Do you want to more genres? ";
  cin >> input;
  if(input == "yes" || input == "Yes"){
    cout << "How many more genres do you want do add?" ;
    cin >> number_new_genres;
    genre_size = genres.size() + number_new_genres;
    genres.resize(genre_size);
    for (int i = 0; i < number_new_genres; i++) {
      cout << "Enter one of the new genres: ";
      cin >> new_genre;
      genres.push_back(new_genre);
    }

    // now coming to the tricky part with adding the bandinfo
    cout << "Now Enter the bandinfo. Whenever you want a new line to " << endl;
    cout << "start simply press enter. if you are finished wrinting enter END";
    while(input != "END"){
      cin >> new_bandinfo;
      new_bandinfo.append("\n");
    }
    // to delete the last new line
    new_bandinfo.pop_back();
    
  }

  return newlist;
}
