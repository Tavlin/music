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
