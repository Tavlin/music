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
  cout << "type: \"new list\" to start a new list." << endl;
  cout << "\"creat list\" to start a new list works too." << endl;
  cout << "type: \"genre\" to search for a specific genre." << endl;
  cout << "type: \"band\" to search for a band." << endl;
  cout << "type: \"song\" to search for a specific song." << endl;
  cout << "type: \"album\" to search for a specific album." << endl;
};

/*******************************************************************************
  function to initialize a new music list.
  maybe needs to be splitted in to seperate functions
*******************************************************************************/
vector<Musicmember> new_list(){

  vector<Musicmember> newlist;

  string input;
  string bandname;
  string new_genre;
  string new_bandinfo;
  string new_songname;
  string new_songinfo;
  string new_album;
  string new_spotifylink;
  string new_youtubelink;
  string new_prio;
  bool new_prio_bool;

  int number_new_genres;
  int number_new_songs;
  int genre_size = 0;
  vector<string> genres;
  string bandinfo;
  vector<song> songlist;

  // start of a new musiclist with bandname input
  cout << "Please enter the bandname: ";
  getline(cin, bandname);
  cout << "bandname = " << bandname;

  // followed by one or more genre(s)
  cout << endl << "Now enter ONE genre of the band: ";
  getline(cin, new_genre);
  genres.resize(1);
  genres = {new_genre};
  cout << "Do you want to more genres? ";
  cin >> input;
  if(input == "yes" || input == "Yes"){
    cout << "How many more genres do you want do add? " << endl;
    cin >> number_new_genres;
    if(number_new_genres > 0){
      genre_size = genres.size() + number_new_genres;
      genres.resize(genre_size);
      for (int i = 0; i < number_new_genres; i++) {
        cout << "Enter one of the new genres: ";
        getline(cin, new_genre);
        genres.push_back(new_genre);
      }
    }
  }

    // now coming to the tricky part with adding the bandinfo
    // might need to change that cool trick, since it might make saving and
    // loading impossibly hart to programm... we'll see
    cout << "Now enter the bandinfo. Whenever you want a new line to " << endl;
    cout << "start simply press enter. If you are finished wrinting enter END.";
    cout << endl;
    getline(cin, input);
    while(input != "END"){
      getline(cin, input);
      new_bandinfo.append(input);
      new_bandinfo.append("\n");
    }

    // to delete the last new line and the END
    for(int i = 0; i < 5; i++){
      new_bandinfo.pop_back();
    }
    cout << endl << "Bandinfo:";
    cout << endl << new_bandinfo << endl;

    // Start of new songlist, first starting with ONE song, asks to be expanded
    // after first song.
    cout << "Now it's time to add a song list. Starting with ONE song title: ";
    cout << endl;
    cin >> new_songname;

    // Songinfo
    cout << "Now Enter the songinfo. Whenever you want a new line to " << endl;
    cout << "start simply press enter. If you are finished writing enter END.";
    cout << endl;
    getline(cin, input);
    while(input != "END"){
      getline(cin, input);
      new_songinfo.append(input);
      new_songinfo.append("\n");
    }

    // to delete the last new line and the END
    for(int i = 0; i < 5; i++){
      new_songinfo.pop_back();
    }


    // adding the info in which album the song was published
    cout << "Time to add on which album this song was released: ";
    cin >> new_album;

    //time for the important stuff, the ducking links:
    cout << "It's finally time to enter the links. Start with Spotify: " << endl;
    cin >> new_spotifylink;

    cout << "Followed by the YouTube-URL: " << endl;
    cin >> new_youtubelink;

    // setting if the song has prio or not.
    cout << "has this song a high priority for you (yes/no)?";
    cin >> new_prio;
    if(new_prio == "yes" || new_prio == "Yes" || new_prio == "YES" || new_prio == "y"){
      new_prio_bool = true;
    }
    else{
      new_prio_bool = false;
    }

    // actual initializing of the first song in this song list coressponding
    // to the current band.
    songlist.resize(1);
    songlist[0] = song_init(new_songname, new_songinfo, new_album,
                            new_spotifylink, new_youtubelink, new_prio_bool);

    cout << "Do you want to add more songs to the song list (yes/no)?";
    cin >> input;
    if(input == "yes" || input == "Yes" || input == "YES" || input == "y"){
      cout << "How many songs would you like to add?";
      cin >> number_new_songs;

      // adding multiple new songs to the song list like before
      for (int i = 0; i < number_new_songs; i++) {
        cout << "Time to add a new song to the list. Songtitle: ";
        cin >> new_songname;
        cout << "Now Enter the songinfo. Whenever you want a new line to " << endl;
        cout << "start simply press enter. If you are finished writing enter END.";
        cout << endl;
        getline(cin, input);
        while(input != "END"){
          getline(cin, input);
          new_songinfo.append(input);
          new_songinfo.append("\n");
        }
        // to delete the last new line and the END
        for(int i = 0; i < 5; i++){
          new_songinfo.pop_back();
        }

        // adding the info in which album the song was published
        cout << "Time to add on which album this song was released: ";
        cin >> new_album;

        //time for the important stuff, the ducking links:
        cout << "It's finally time to enter the links. Start with Spotify: " << endl;
        cin >> new_spotifylink;

        cout << "Followed by the YouTube-URL: " << endl;
        cin >> new_youtubelink;

        // setting if the song has prio or not.
        cout << "has this song a high priority for you (yes/no)?";
        cin >> new_prio;
        if(new_prio == "yes" || new_prio == "Yes" || new_prio == "YES" || new_prio == "y"){
          new_prio_bool = true;
        }
        else{
          new_prio_bool = false;
        }
        songlist.push_back(song_init(new_songname, new_songinfo, new_album,
                                     new_spotifylink, new_youtubelink,
                                     new_prio_bool));

      }
      cout << "So this was all to start a new music list. Done for now" << endl;
      Musicmember new_musicmember(bandname, genres, bandinfo, songlist);
      newlist = {new_musicmember};

    }
  return newlist;
}
