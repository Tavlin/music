class song:
    """A class that contains all kind of informations about a song.
    """
    def __init__(self, songname, songinfo, album, spotifylink, youtubelink,
                 prio, addstatus):
        self.songname = songname
        self.songinfo = songinfo
        self.album = album
        self.spotifylink = spotifylink
        self.youtubelink = youtubelink
        self.prio = prio
        self.addstatus = addstatus


class Musicmember:
    """A class to contain different informations about a band you like and your
    favorite songs.
    It contains the bandname, a list of the genres the band plays, a text about
    the band, like from where you know it or why you like it. Then there is the
    songlist, which itself is a complex type.
    """
    def __init__(self, bandname, genres, bandinfo, songlist):
        self.bandname = bandname
        self.genres = genres
        self.bandinfo = bandinfo
        self.songlist = songlist

    def AddSong(self, added_song):
        self.songlist.append(added_song)

    def AddGenre(self, added_genre):
        """function to add a Genre to the list of genres
        """
        self.genres.append(added_genre)

    def AddBandInfo(self, added_bandinfo):
        """function to add additional info about the band.
        """
        self.bandinfo.append("\n")
        self.bandinfo.append(added_bandinfo)

    def ChangeBandname(self, new_bandname):
        """function to change the name of the band if you missspelled it.
        """
        self.bandname = new_bandname

    def ChangeBandinfo(self, new_bandinfo):
        """function to change the info of the band.
        """
        self.bandinfo = new_bandinfo

    def PrintMusicmember(self):
        """function to print the name of the band and it's genres.
        """
        size_genres = self.genres.size()
        for i in range(0, size_genres):
            if i < (size_genres - 1):
                print(self.genres[i], " ")
            else:
                print(self.genres[i], " : ")

        print(self.bandname)
