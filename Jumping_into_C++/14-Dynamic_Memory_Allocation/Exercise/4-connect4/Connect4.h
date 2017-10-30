#ifndef CONNECT4_H
#define CONNECT4_H

class Connect4
{
public:
    Connect4(const int a_height = 6, 
             const int a_width  = 7, 
             const int a_rows   = 4);
    ~Connect4();

    void resetBoard(char    **a_board, 
                   const int a_height, 
                   const int a_width, 
                   const char = '_');

    void start(const char a_player1, 
               const char a_player2);

    bool dropDisc(const int  a_width, 
                  const char a_player);

    bool connect4(const char a_player) const;

    bool horizontal4(const int  a_height, 
                     const int  a_width, 
                     const char a_player) const;

    bool vertical4(const int  a_height,
                   const int  a_width,
                   const char a_player) const;

    bool diagonal4(const int  a_height,
                   const int  a_width,
                   const char a_player) const;

    void printBoard() const;
    void startMessage(const char a_player1, 
                      const char a_player2) const;
    void printInfo() const;

private:
    int  m_height;      // board height
    int  m_width;       // board width
    int  m_rows;        // number of sequentail rows
    char m_emptySpace;  // empty space symbol
    char **m_board;     // the connect4 board
    
    // utility functions 
    bool _isEmpty(const int a_height, const int a_width) const;
    void _setHeight(const int a_height);
    void _setWidth(const int  a_width);
    void _setRows(const int   a_rows);
    void _winnerMessage(const char a_player) const;

};

#endif
