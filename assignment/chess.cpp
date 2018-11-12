/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdlib.h>
 #include "general.h"
 #include "chess.h"


 bool is_square_ok (File file, Rank rank)
 {
   return (file - 'a' >= 1 && file - 'a' <= 8 && rank >= 1 && rank <= 8 );
 }
 int nr(Rank rank)
 {
   return rank;
 }
 int nf(File file)
 {
   return file;
 }
 bool	is_move_from_base_line (enum PieceColor color, Rank rank)
 {
   if (color == Black) {
     return (rank < 8);
   }
   if (color == White) {
     return (rank > 1);
   }

   return false;
 }
 bool is_piece(struct ChessPiece pc, enum PieceColor color, enum PieceType type)
 {
   return pc.color == color && pc.type == type;
 }

 void init_chess_board(ChessBoard chess_board)
 {
   for(int i = 0; i <  8; i++)
   {
     for(int j = 0; j < 8; j++)
     {
       chess_board[i][j].is_occupied = false;
       chess_board[i][j].piece.type=NoPiece;
     }
   }
 }

 struct ChessSquare* get_square(ChessBoard chess_board, File file, Rank rank)
 {
   return 0;
 }

 bool is_square_occupied(ChessBoard chess_board, File file, Rank rank)
 {
   return false;
 }

 bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece)
 {
   return false;
 }

 struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank)
 {
   return chess_board[file - 1][rank -1].piece;
 }

 void setup_chess_board(ChessBoard chess_board)
 {

 }
 bool remove_piece(ChessBoard chess_board, File file, Rank rank)
 {
   return false;
 }

 bool squares_share_file(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }

 bool squares_share_rank(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }

 bool squares_share_diagonal(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }

 bool squares_share_knights_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }

 bool squares_share_pawns_move(enum PieceColor color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }

 bool squares_share_queens_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }

 bool squares_share_kings_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   if (is_square_ok(s1_f,s1_r) == true && is_square_ok(s2_f,s2_r) == true)
   {
      if (s1_r == s2_r-1 || s2_r == s1_r-1 || s2_r == s1_r)
      {
        return true;
      }
   }
   return false;
 }
