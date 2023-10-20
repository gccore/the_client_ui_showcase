#pragma once

template <typename LayoutType, typename Functor, typename... ItemType>
auto constexpr PackItemsToLayout(Functor functor, ItemType... items) {
  auto* const layout = new LayoutType;
  (functor(layout, items), ...);
  return layout;
}

template <typename LayoutType, typename... WidgetType>
auto constexpr PackWidgetsToLayout(WidgetType... widgets) {
  return PackItemsToLayout<LayoutType>(
      std::bind(&LayoutType::addWidget, std::placeholders::_1,
                std::placeholders::_2, 0, Qt::Alignment()),
      widgets...);
}
template <typename LayoutType, typename... LayoutsType>
auto constexpr PackLayoutsToLayout(LayoutsType... layouts) {
  return PackItemsToLayout<LayoutType>(
      std::bind(&LayoutType::addLayout, std::placeholders::_1,
                std::placeholders::_2, 0),
      layouts...);
}

template <int Value>
inline int constexpr Column = Value;
template <int Value>
inline int constexpr Row = Value;
template <int Value>
inline int constexpr Index = Value;