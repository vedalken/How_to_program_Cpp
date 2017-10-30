#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include "Connect4.h"

Connect4::Connect4(const int a_height, 
                   const int a_width, 
                   const int a_rows)
{
    _setHeight(a_height);
    _setWidth(a_width);
    _setRows(a_rows);
    m_emptySpace = {'_'};

    m_board = new char*[m_height];
    for (int h = 0; h < m_height; ++h)
        m_board[ h ] = new char [m_width];

    resetBoard(m_board, m_height, m_width);
}

Connect4::~Connect4()
{
    for (int h = 0; h < m_height; ++h)
        delete[] m_board[ h ];

    delete[] m_board;
}

void Connect4::resetBoard(char **a_board, const int a_height, const int a_width, const char ch)
{
    for (int h = 0; h < a_height; ++h) {
        for (int w = 0; w < a_width; ++w) {
            a_board[ h ][ w ] = {ch};
        }
    }
}

void Connect4::start(const char a_player1, const char a_player2)
{
    startMessage(a_player1, a_player2);
    
    int moves = 0;
    // total allowed moves
    const int maxMoves = m_height * m_width;

    while (moves <= maxMoves) 
    {
        char input, slot;
        int player;
        player = moves % 2 + 1;
       
        printInfo();
        std::cout << "[ Player " << player << " ]: ";
        std::cin >> input;
        
        switch (input) {
            case 'd':
                std::cout << "Drop the disc into a slot [1," << m_width << "] : ";
                std::cin >> slot;

                if (slot == '0' || !std::isdigit(slot)) {
                    std::cerr << "Please enter appropriate slot number." << std::endl;
                    std::cerr << "Enter disk slot between [1," << m_width << "]" << std::endl;
                    continue;
                }
                break;

            case 'e':
                std::cout << "Exiting..." << std::endl;
                return;
            
            case 'p': printBoard();
            default:
                continue;
        }
        
        // determine the player
        const char * playerN = (player % 2) ? &a_player1 : &a_player2;
        
        if (!dropDisc(std::atoi(&slot)-1, *playerN))
            continue;
        
        std::cout << "player: " << *playerN << std::endl;
        if (connect4(*playerN)) {
            printBoard();
            break;
        }

        // next player
        ++moves;
    }
}

bool Connect4::dropDisc(const int a_width, const char a_player)
{
    if (a_width < 0) {
        std::cerr << "(dropDisc) Width is negative" << std::endl;
        return false;
    }
    
    for (int h = m_height-1; h >= 0; --h) {
        if (m_board[ h ][ a_width ] == m_emptySpace) {
            m_board[ h ][ a_width ] = {a_player};
            return true;
        }
    }

    return false;
}

// Determine the connect4
bool Connect4::connect4(const char a_player) const
{
    for (int h = 0; h < m_height; ++h) 
    {
        for (int w = 0; w < m_width; ++w) 
        {
            // skip empty slot position
            if (_isEmpty(h, w))
                continue;

            // check horizontal four in a row
            if (horizontal4(h, w, a_player))
                return true;

            // check vertical four in a row
            if (vertical4(h, w, a_player))
                return true;

            // check diagonal four in a row
            if (diagonal4(h, w, a_player))
                return true;
        }
    }

    return false;
}

bool Connect4::horizontal4(const int a_height, 
                           const int a_width,
                           const char a_player) const
{
    if (a_height < 0 || a_height >= m_height) {
        std::cerr << "Invalid height position!" << std::endl;
        return false;
    }

    if (a_width < 0 || a_width >= m_width) {
        std::cerr << "Invalid width position!" << std::endl;
        return false;
    }

    if (_isEmpty(a_height, a_width))
        return false;

    // check any sequnetial horizontal toss match
    for (int leftShift = 0; std::abs(leftShift) < m_rows; --leftShift) 
    {
        // start and end position
        int startPos, endPos;
        startPos = a_width  + leftShift;
        endPos   = startPos + m_rows - 1; 
        
        if (startPos < 0 || startPos >= m_width)
            continue;

        if (endPos >= m_width || endPos < 0)
            continue;

        // connect4 counter
        int connect4 = {0};

        // check row connection
        for (int w = endPos; w >= startPos; --w) {
            if (m_board[ a_height ][ w ] != a_player) {
                return false;
            }
            ++connect4;
        }
        
        // found N in a row
        if (connect4 >= m_rows)
            return true;
    }

    return false;
}//end function horizontal4


bool Connect4::vertical4(const int a_height, 
                         const int a_width,
                         const char a_player) const
{
    if (a_height < 0 || a_height >= m_height) {
        std::cerr << "Invalid height position!" << std::endl;
        return false;
    }

    if (a_width < 0 || a_width >= m_width) {
        std::cerr << "Invalid width position!" << std::endl;
        return false;
    }
    
    if (_isEmpty(a_height, a_width))
        return false;
    
    // check any sequential vertical match N in a row, where N = 2,3,4,...
    for (int downShift = 0; std::abs(downShift) < m_rows; --downShift) 
    {
        // start and end position
        int startPos = a_height + downShift;
        int endPos   = startPos + m_rows - 1; 
       
        // out of bound, nothing to do
        if (startPos < 0 || startPos >= m_height)
            continue;

        // out of bound, nothing to do
        if (endPos >= m_height || endPos < 0)
            continue;
        
        // connect4 counter
        int connect4 = 0;

        // check vertical N in a row
        for (int h = endPos; h >= startPos; --h) {
            if (m_board[ h ][ a_width ] != a_player) {
                return false;
            }
            ++connect4;
        }
        
        // found N in a row
        if (connect4 >= m_rows)
            return true;
    }

    return false;
}//end function vertical4

bool Connect4::diagonal4(const int a_height,
                         const int a_width,
                         const char a_player) const
{
    if (a_height < 0 || a_height >= m_height) {
        std::cerr << "Invalid height position!" << std::endl;
        return false;
    }

    if (a_width < 0 || a_width >= m_width) {
        std::cerr << "Invalid width position!" << std::endl;
        return false;
    }
    
    if (_isEmpty(a_height, a_width))
        return false;
    
    // check any sequnetial toss match
    for (int diagShift = 0; std::abs(diagShift) < m_rows; --diagShift) 
    {
        // vertical and horizontal start and end position
        int heightStartPos, heightEndPos;
        int widthStartPos,  widthEndPos;

        heightStartPos = a_height + diagShift;
        widthStartPos  = a_width  + diagShift;
        heightEndPos   = heightStartPos + m_rows - 1;
        widthEndPos    = widthStartPos  + m_rows - 1;
        
        if (heightStartPos < 0 || heightStartPos >= m_height)
            return false;

        if (heightEndPos >= m_height || heightEndPos < 0)
            return false;

        if (widthStartPos < 0 || widthStartPos >= m_height)
            return false;

        if (widthEndPos >= m_height || widthEndPos < 0)
            return false;
        
        // connect4 counter
        int connect4 = 0;
        
        // check diagonal connection
        for (int h = heightStartPos, w = widthStartPos; h <= heightEndPos ; ++h, ++w) {
            if (m_board[ h ][ w ] != a_player) {
                return false;
            }
            ++connect4;
        }
        
        // found N in a row
        if (connect4 >= m_rows)
            return true;
    }

    return false;
}// end function diagonal4

bool Connect4::_isEmpty(const int a_height, const int a_width) const
{
    return (m_board[ a_height ][ a_width ] == m_emptySpace) ? true : false; 
}

void Connect4::_setHeight(const int a_height)
{
    if (a_height > 0) {
        m_height = a_height;
    }
    else {
        throw std::invalid_argument("Non-positive height.");
    }
}

void Connect4::_setWidth(const int a_width)
{
    if (a_width > 0) {
        m_width = a_width;
    }
    else {
        throw std::invalid_argument("Non-positive width.");
    }
}

void Connect4::_setRows(const int a_rows)
{
    if (a_rows > 0) {
        m_rows = a_rows;
    }
    else {
        throw std::invalid_argument("Non-positive number of rows");
    }
}

void Connect4::printBoard() const
{
    for (int h = 0; h < m_height; ++h) {
        for (int w = 0; w < m_width; ++w) {
            std::cout << std::setw(5) << m_board[ h ][ w ];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Connect4::startMessage(const char a_player1, 
                            const char a_player2) const
{
    std::cout
        << "***************************************\n"
        << "   Welcome to Connect-Four Game Play\n"
        << "***************************************\n"
        << " Player 1: " << a_player1 << '\n'
        << " Player 2: " << a_player2 << '\n'
        << "***************************************\n\n";
}

void Connect4::printInfo() const
{
    std::cout
        << "----------------------------------\n"
        << "The list of available commands    \n"
        << "----------------------------------\n"
        << "[command]  [description]          \n"
        << "---------  -------------          \n"
        << "d          drop the disk          \n"
        << "e          exit the program       \n"
        << "p          print the board        \n"
        << "----------------------------------\n"
        << std::endl;
}

void Connect4::_winnerMessage(const char a_player) const
{
    std::cout << "The player " << a_player << " has " << m_rows << " in a row!\n"
              << "*******************************\n"
              << "**** You are the winner !! ****\n" 
              << "*******************************\n"
              << std::endl;
}
