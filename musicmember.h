#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>

#ifndef Musicmember_h
#define Musicmember_h
using namespace std;

/*******************************************************************************
struct for a single song, including the songname, the info about the song,
the URL to open the song in spotify and the URL to open it on YouTube.
*******************************************************************************/
struct song{
  string songname;
  string songinfo;
  string album;
  string spotifylink;
  string youtubelink;
  bool prio;

};

song creat_song(string, string, string, string ,string, bool);

/*******************************************************************************
class which contains one band, all the genres, all their important songs and
the band info
*******************************************************************************/
class Musicmember
{
  public:
    string bandname;
    vector<string> genres;
    string bandinfo;
    vector<song> songlist;

    // normal constructor
    Musicmember(string, vector<string>, string, vector<song>);

    // function to add a new song to the songlist
    void AddSong(song added_song)
    {
      Musicmember::songlist.push_back(added_song);
    }

    // function to add a Genre to the list of genres
    void AddGenre(string added_genre)
    {
      Musicmember::genres.push_back(added_genre);
    }

    // function to add additional info about the band
    void AddBandInfo(string added_bandinfo)
    {
      Musicmember::bandinfo.append("\n");
      Musicmember::bandinfo.append(added_bandinfo);
    }

    // function to change the name of the band if you missspelled it
    void ChangeBandname(string new_bandname)
    {
      Musicmember::bandname = new_bandname;
    }

    // function to change the info of the band
    void ChangeBandinfo(string new_bandinfo)
    {
      Musicmember::bandinfo = new_bandinfo;
    }

    void PrintMusicmember()
    {
      int size_genres = Musicmember::genres.size();
      for (int i = 0; i < size_genres; i++) {
        if(i < size_genres - 1){
          cout << Musicmember::genres[i] << " ";
        }
        else{
          cout << Musicmember::genres[i] << ":" << endl;
        }

      }
      cout << Musicmember::bandname << endl;

    }
};
void search_genre(vector<Musicmember> list, string searched_genre);
void print_commands();
#endif
