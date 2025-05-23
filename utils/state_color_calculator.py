from PySide6.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QGroupBox, QGridLayout, QLabel, QLineEdit, QPushButton, QFrame
from PySide6.QtCore import QSize, Qt
import sys

class StateLayerCalculator(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("State Layer Calculator")
        self.build_ui()

    def build_ui(self):
        self.main_layout = QVBoxLayout(self)
        self.setLayout(self.main_layout)

        # Input group
        self.input_group = QGroupBox()
        self.input_group.setTitle("输入 · Input")
        self.main_layout.addWidget(self.input_group)

        self.form_layout = QGridLayout()
        self.input_group.setLayout(self.form_layout)

        self.base_color_label = QLabel()
        self.base_color_label.setText("底色 · Base color: ")
        self.form_layout.addWidget(self.base_color_label, 0, 0)

        self.base_color_edit = QLineEdit()
        self.base_color_edit.setPlaceholderText("十六进制或者RGBA · HEX or RGBA")
        self.form_layout.addWidget(self.base_color_edit, 0, 1)

        self.state_color_label = QLabel()
        self.state_color_label.setText("状态色 · State color: ")
        self.form_layout.addWidget(self.state_color_label, 1, 0)

        self.state_color_edit = QLineEdit()
        self.state_color_edit.setPlaceholderText("十六进制或者RGBA · HEX or RGBA")
        self.form_layout.addWidget(self.state_color_edit, 1, 1)

        # Output group
        self.output_group = QGroupBox()
        self.output_group.setTitle("输出 · Output")
        self.main_layout.addWidget(self.output_group)

        self.result_layout = QHBoxLayout()
        self.output_group.setLayout(self.result_layout)

        self.color_preview = QLabel()
        self.color_preview.setFixedSize(QSize(16, 16))
        self.color_preview.setStyleSheet("QLabel { background: transparent; border: 1px solid #ccc; } ")
        self.result_layout.addWidget(self.color_preview)

        self.color_hex = QLabel()
        self.color_hex.setText("HEX #??????")
        self.result_layout.addWidget(self.color_hex)

        self.copy_hex = QPushButton()
        self.copy_hex.setText("复制 · Copy")
        self.result_layout.addWidget(self.copy_hex)

        self.color_rgba = QLabel()
        self.color_rgba.setText("rgba(??, ??, ??, ??)")
        self.result_layout.addWidget(self.color_rgba)

        self.copy_rgba = QPushButton()
        self.copy_rgba.setText("复制 · Copy")
        self.result_layout.addWidget(self.copy_rgba)

        self.horizontal_divider = QFrame()
        self.horizontal_divider.setFrameShape(QFrame.HLine)
        self.horizontal_divider.setFrameShadow(QFrame.Sunken)
        self.main_layout.addWidget(self.horizontal_divider)

        self.instructions = QLabel()
        self.instructions.setWordWrap(True)
        self.instructions.setTextFormat(Qt.TextFormat.RichText)
        self.instructions.setText(
            "此工具用于计算Material Design 3中\"<code>md.sys.state.hover.state-layer-opacity</code>\"叠加在原来颜色上之后所呈现的颜色。<br/>" \
            "输入底色和叠加色（如果配色表没有定义叠加色，其可以是对应的\"<code>onSurface</code>\"或者\"<code>onPrimary</code>\"等，但取决于底色，即可在\"输出\"中看到结果。<br/><br/>" \
            "This tool is used to calcuate the resulting color produced when a state layer, defined by \"<code>md.sys.state.hover.state-layer-opacity</code>\" in Material Design 3 is put on the base color. <br/>" \
            "Enter the base color and the state color (if not defined, depending on what base color is it could be \"<code>onSurface</code>\" or \"<code>onPrimary</code>\", etc.) and then your result is on the \"Output\" section."
        )
        self.main_layout.addWidget(self.instructions)

def main():
    app = QApplication(sys.argv)
    window = StateLayerCalculator()
    window.show()
    sys.exit(app.exec())

if __name__ == "__main__":
    main()