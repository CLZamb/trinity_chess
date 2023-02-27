set(chess ${CMAKE_PROJECT_NAME})

set(SOURCE_FILES main.cpp)

add_executable(${chess} ${SOURCE_FILES})

add_subdirectory(board)
add_subdirectory(common)
add_subdirectory(configuration)
add_subdirectory(controller)
add_subdirectory(graphics)
add_subdirectory(ipc)
add_subdirectory(model)
add_subdirectory(game)
add_subdirectory(piece)
add_subdirectory(player)
# add_subdirectory(search)
add_subdirectory(view)

target_link_libraries(${chess} PUBLIC board_lib)
# target_link_libraries(${chess} PUBLIC common_lib)
target_link_libraries(${chess} PUBLIC configuration_lib)
target_link_libraries(${chess} PUBLIC controller_lib)
target_link_libraries(${chess} PUBLIC graphics_lib)
# target_link_libraries(${chess} PUBLIC ipc_lib)
target_link_libraries(${chess} PUBLIC game_lib)
target_link_libraries(${chess} PUBLIC model_lib)
target_link_libraries(${chess} PUBLIC piece_lib)
target_link_libraries(${chess} PUBLIC player_lib)
# target_link_libraries(${chess} PUBLIC search_lib)
target_link_libraries(${chess} PUBLIC view_lib)

target_include_directories(
  ${chess} PUBLIC 
  "${PROJECT_SOURCE_DIR}/board/headers"
  "${PROJECT_SOURCE_DIR}/common/headers"
  "${PROJECT_SOURCE_DIR}/configuration/headers"
  "${PROJECT_SOURCE_DIR}/controller/headers"
  "${PROJECT_SOURCE_DIR}/graphics/headers"
  "${PROJECT_SOURCE_DIR}/ipc/headers"
  "${PROJECT_SOURCE_DIR}/model/headers"
  "${PROJECT_SOURCE_DIR}/game/headers"
  "${PROJECT_SOURCE_DIR}/piece/headers"
  "${PROJECT_SOURCE_DIR}/player/headers"
  "${PROJECT_SOURCE_DIR}/view/headers"
  # "${PROJECT_SOURCE_DIR}/search/headers"
)
