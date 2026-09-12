#include <iostream>
#include <string>

using namespace std;

enum class Color {
    White,
    Black
};

enum class PieceType {
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

int main() {
    Piece whiteKing {PieceType::King, Color::White};
    Piece blackQueen {PieceType::Queen, Color::Black};
    Piece whitePawn {PieceType::Pawn, Color::White};

    cout << "Chess pieces in our engine:\n";

    printPiece(whiteKing);
    printPiece(blackQueen);
    printPiece(whitePawn);

    return 0;
}