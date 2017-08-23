import QtQuick 2.7

ClockForm {
  date: clock.now.toLocaleDateString(Qt.locale(), "d MMM yyyy")
  time: clock.now.toLocaleTimeString(Qt.locale(), "HH:mm")
  day: clock.now.toLocaleDateString(Qt.locale(), "dddd")
}
