#include <iostream>
#include <string>

using namespace std;

enum class Color {
    White,
    Black
};

enum class PieceType {
    None,
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};

struct Piece {
    PieceType type;
    Color color;
};

struct Square {
    char file;
    int rank;
};

struct Move {
    Square from;
    Square to;
    PieceType promotion;
};

string colorToString(Color color) {
    switch (color) {
        case Color::White:
            return "White";

        case Color::Black:
            return "Black";
    }

    return "Unknown";
}

string pieceTypeToString(PieceType pieceType) {
    switch (pieceType) {
        case PieceType::None:
            return "None";

        case PieceType::Pawn:
            return "Pawn";

        case PieceType::Knight:
            return "Knight";

        case PieceType::Bishop:
            return "Bishop";

        case PieceType::Rook:
            return "Rook";

        case PieceType::Queen:
            return "Queen";

        case PieceType::King:
            return "King";
    }

    return "Unknown";
}

void printPiece(const Piece& piece) {
    cout << colorToString(piece.color)
         << " "
         << pieceTypeToString(piece.type)
         << '\n';
}

bool isValidSquare(const Square& square) {
    return square.file >= 'a' &&
           square.file <= 'h' &&
           square.rank >= 1 &&
           square.rank <= 8;
}

string squareToString(const Square& square) {
    string result;

    result += square.file;
    result += to_string(square.rank);

    return result;
}

string moveToString(const Move& move) {
    string result = squareToString(move.from) + squareToString(move.to);
    if(move.promotion!=PieceType::None){
       result+= "="+ pieceTypeToString(move.promotion);
    }
    return result;
}

void printMove(const Move& move) {
    if (!isValidSquare(move.from) || !isValidSquare(move.to)) {
        cout << "Invalid move\n";
        return;
    }

    cout << "Move: " << moveToString(move) << '\n';
}

int main() {
    Piece whiteKing {PieceType::King, Color::White};
    Piece blackQueen {PieceType::Queen, Color::Black};
    Piece whitePawn {PieceType::Pawn, Color::White};

    cout << "Chess pieces in our engine:\n";

    printPiece(whiteKing);
    printPiece(blackQueen);
    printPiece(whitePawn);

    Move pawnMove = {{'e', 2}, {'e', 4}, PieceType::None};
    Move knightMove = {{'g', 1}, {'f', 3}, PieceType::None};
    Move promotionMove = {{'e', 7}, {'e', 8}, PieceType::Queen};

    cout << "\nChess moves in our engine:\n";

    printMove(pawnMove);
    printMove(knightMove);
    printMove(promotionMove);

    return 0;
}