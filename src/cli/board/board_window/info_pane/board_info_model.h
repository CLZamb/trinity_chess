#ifndef BOARD_INFO_MODEL_H
#define BOARD_INFO_MODEL_H

#include <array>
#include <string>

#include "IBoard_info_getter.h"
#include "IBoard_info_updater.h"

class BoardInfoModel : public IBoardInfoGetter,
                       public IBoardSaveInfo {
 public:
  BoardInfoModel();
  virtual ~BoardInfoModel();

  void update_turn(const Color &info) ;
  void save_side(const Color &p);
  void save_move(const Move &m);
  void save_capture(const Move &m);
  void save_info(const std::string &info) override;

  std::string get_moves(Color c) override;
  std::string get_captures(Color c) override;
  std::string get_info() override;
  Color get_side_to_move_color() override;

 private:
  std::string get_move_string(const Move &m);
  std::string get_captured_string(const Move &m);

  Color m_side;
  static const size_t players_size = Color::SIZE;
  std::array<std::string, players_size> m_moves;
  std::array<std::string, players_size> m_captures;
  std::string m_info;
  std::array<std::string, Color::SIZE> m_turn_string{"Is white turn",
                                                     "Is black turn"};
};

#endif /* BOARD_INFO_MODEL_H */
