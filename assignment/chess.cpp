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
 #include "math.h"


 bool is_square_ok (File file, Rank rank)
 {
      return (file >= 'a'&& file <= 'h' && rank >= 1 && rank <= 8 );
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
     }
   }
 }

 struct ChessSquare* get_square(ChessBoard chess_board, File file, Rank rank)
 {
   if (is_square_ok(file, rank))
   {
     return &chess_board[rank-1][file-'a'];
   }
   else
   {
     return 0;
   }
 }

 bool is_square_occupied(ChessBoard chess_board, File file, Rank rank)
 {
   return chess_board[rank-1][file-'a'].is_occupied;
 }

 bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece)
 {
   if (is_square_ok(file, rank)==true && !is_square_occupied(chess_board, file, rank))
   {
     chess_board[rank-1][file-'a'].is_occupied = true;
     chess_board[rank-1][file-'a'].piece = piece;
     return true;
   }
   else
   {
     return false;
   }
 }

 struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank)
 {
   struct ChessPiece x;
    x.type=NoPiece;
    if(is_square_ok(file,rank)==true)
    {
      return chess_board[rank- 1][file-'a'].piece;
    }
    else{return x;}
  }


 void setup_chess_board(ChessBoard chess_board)
 {
   init_chess_board(chess_board);
   for (char x = 'a'; x <= 'h'; x++)
   {
     add_piece(chess_board, x, 2, {White, Pawn});
     add_piece(chess_board, x, 7, {Black, Pawn});
   }
   add_piece(chess_board, 'a', 1, {White, Rook});
   add_piece(chess_board, 'h', 1, {White, Rook});
   add_piece(chess_board, 'b', 1, {White, Knight});
   add_piece(chess_board, 'g', 1, {White, Knight});
   add_piece(chess_board, 'c', 1, {White, Bishop});
   add_piece(chess_board, 'f', 1, {White, Bishop});
   add_piece(chess_board, 'd', 1, {White, Queen});
   add_piece(chess_board, 'e', 1, {White, King});
   add_piece(chess_board, 'a', 8, {Black, Rook});
   add_piece(chess_board, 'h', 8, {Black, Rook});
   add_piece(chess_board, 'b', 8, {Black, Knight});
   add_piece(chess_board, 'g', 8, {Black, Knight});
   add_piece(chess_board, 'c', 8, {Black, Bishop});
   add_piece(chess_board, 'f', 8, {Black, Bishop});
   add_piece(chess_board, 'd', 8, {Black, Queen});
   add_piece(chess_board, 'e', 8, {Black, King});
  }

 bool remove_piece(ChessBoard chess_board, File file, Rank rank)
 {
   if (is_square_occupied(chess_board,file,rank) == true) {
      chess_board[rank-1][file-'a'] = {0};
      return true;
    }
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
