from PySide6.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QGroupBox, QGridLayout, QLabel, QLineEdit, QPushButton, QFrame, QDoubleSpinBox, QCheckBox
from PySide6.QtCore import QSize, Qt
from enum import Enum
import sys

class ErrColorInput(Enum):
    BASE = -1
    STATE = -2

class Color:
    def __init__(self, r, g, b, a):
        self.r = r
        self.g = g
        self.b = b
        self.a = a

    def set_r(self, new_r: int):
        self.r = new_r

    def get_r(self):
        return self.r
    
    def set_g(self, new_g: int):
        self.g = new_g

    def get_g(self):
        return self.g
    
    def set_b(self, new_b: int):
        self.b = new_b

    def get_b(self):
        return self.b
    
    def set_a(self, new_a: int):
        self.a = new_a

    def get_a(self):
        return self.a

class StateLayerCalculator(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("颜色叠加计算器 · State Layer Calculator")
        self.build_ui()
        self.base_color_in = Color(0, 0, 0, 0)
        self.state_color_in = Color(0, 0, 0, 0)
        self.color_gen = Color(0, 0, 0, 0)
        self.color_gen_hex = ""
        self.color_gen_rgba = ""
        self.invalid_color = False

    def build_ui(self):
        self.main_layout = QVBoxLayout(self)
        self.setLayout(self.main_layout)

        self.input_group = QGroupBox()
        self.input_group.setTitle("输入 · Input")
        self.main_layout.addWidget(self.input_group)

        self.input_layout = QVBoxLayout()
        self.input_group.setLayout(self.input_layout)

        self.form_layout = QGridLayout()
        self.form_layout.setContentsMargins(0, 0, 0, 0)
        self.input_layout.addLayout(self.form_layout)

        self.base_color_label = QLabel()
        self.base_color_label.setText("底色 · Base color: ")
        self.form_layout.addWidget(self.base_color_label, 0, 0)

        self.base_color_edit = QLineEdit()
        self.base_color_edit.setPlaceholderText("十六进制或者RGBA · HEX or RGBA")
        self.base_color_edit.textChanged.connect(self.update_color)
        self.form_layout.addWidget(self.base_color_edit, 0, 1)

        self.color_indicator_base = QLabel();
        self.color_indicator_base.setText("请输入颜色...\nWaiting for input...")
        self.color_indicator_base.setStyleSheet("QLabel { color: black; font-size: normal; font-style: italic; }")
        self.form_layout.addWidget(self.color_indicator_base, 1, 1)

        self.state_color_label = QLabel()
        self.state_color_label.setText("状态色 · State color: ")
        self.form_layout.addWidget(self.state_color_label, 2, 0)

        self.state_color_edit = QLineEdit()
        self.state_color_edit.setPlaceholderText("十六进制或者RGBA · HEX or RGBA")
        self.state_color_edit.textChanged.connect(self.update_color)
        self.form_layout.addWidget(self.state_color_edit, 2, 1)

        self.color_indicator_state = QLabel();
        self.color_indicator_state.setText("请输入颜色...\nWaiting for input...")
        self.color_indicator_state.setStyleSheet("QLabel { color: black; font-size: normal; font-style: italic; }")
        self.form_layout.addWidget(self.color_indicator_state, 3, 1)

        self.opacity_desc = QLabel()
        self.opacity_desc.setText("不透明度 · Opacity: ")
        self.form_layout.addWidget(self.opacity_desc, 4, 0)

        self.opacity_edit = QDoubleSpinBox()
        self.opacity_edit.setMinimum(0.0)
        self.opacity_edit.setMaximum(1.0)
        self.opacity_edit.setSingleStep(0.01)
        self.opacity_edit.setValue(0.0)
        self.opacity_edit.valueChanged.connect(self.update_color)
        self.form_layout.addWidget(self.opacity_edit, 4, 1)

        self.auto_omit_alpha_check_box = QCheckBox()
        self.auto_omit_alpha_check_box.setText("自动忽略Alpha通道 · Auto-omit alpha channel")
        self.auto_omit_alpha_check_box.toggled.connect(self.update_color)
        self.input_layout.addWidget(self.auto_omit_alpha_check_box)

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
        self.color_hex.setText("HEX #RRGGBBAA")
        self.result_layout.addWidget(self.color_hex)

        self.copy_hex = QPushButton()
        self.copy_hex.setText("复制 · Copy")
        self.copy_hex.clicked.connect(self.copy_hex_to_clipboard)
        self.copy_hex.hide()
        self.result_layout.addWidget(self.copy_hex)

        self.color_rgba = QLabel()
        self.color_rgba.setText("rgba(rr, gg, bb, aa)")
        self.result_layout.addWidget(self.color_rgba)

        self.copy_rgba = QPushButton()
        self.copy_rgba.setText("复制 · Copy")
        self.copy_rgba.clicked.connect(self.copy_rgba_to_clipboard)
        self.copy_rgba.hide()
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

    def update_color(self):
        print("[INFO] Main UI: Updating color input...")
        if self.format_color_input(self.base_color_edit.text(), True) == True and self.format_color_input(self.state_color_edit.text(), False) == True:
            self.generate_color()
        else:
            self.color_preview.setStyleSheet("QLabel { background: transparent; border: 1px solid #ccc; } ")
            self.color_rgba.setText("rgba(rr, gg, bb, aa)")
            self.color_hex.setText("HEX #RRGGBBAA")
            self.copy_hex.hide()
            self.copy_rgba.hide()


    def format_color_input(self, input, is_base_color: bool):
        input = input.lower()
        input = input.replace("，", ",")
        input = input.replace("（", "")
        input = input.replace("）", "")
        input = input.replace("(", "")
        input = input.replace(")", "")
        input = input.replace("rgb", "")
        input = input.replace("a", "")
        input = input.replace(" ", "")
        
        if input == "":
            if is_base_color:
                self.color_indicator_base.setText("请输入颜色...\nWaiting for input...")
                self.color_indicator_base.setStyleSheet("QLabel { color: black; font-size: normal; font-style: italic; }")
                return False
        
            else:
                self.color_indicator_state.setText("请输入颜色...\nWaiting for input...")
                self.color_indicator_state.setStyleSheet("QLabel { color: black; font-size: normal; font-style: italic; }")
                return False
        
        print("[INFO] Formatter - Got Color input: " + input + ".")

        if "," in input:
            print("[INFO] Formatter - Detected format: RGBA")
            channels = input.split(",")
            channels_int = [0, 0, 0, 255]

            if len(channels) < 3:
                if is_base_color:
                    self.throw_color_invalid_errror("Formatter", ErrColorInput.BASE)
                    return False

                else:
                    self.throw_color_invalid_errror("Formatter", ErrColorInput.STATE)
                    return False

            else:
                for i in range(0, len(channels), 1):
                    if channels[i] == "":
                        if is_base_color:
                            self.throw_color_invalid_errror("Formatter", ErrColorInput.BASE)
                            return False

                        else:
                            self.throw_color_invalid_errror("Formatter", ErrColorInput.STATE)
                            return False

                    try:
                        channels_int[i] = int(channels[i])
                        if channels_int[i] > 255 or channels_int[i] < 0:
                            if is_base_color:
                                self.throw_color_invalid_errror("Formatter", ErrColorInput.BASE)
                                return False

                            else:
                                self.throw_color_invalid_errror("Formatter", ErrColorInput.STATE)
                                return False

                    except ValueError:
                        if is_base_color:
                            self.throw_color_invalid_errror("Formatter", ErrColorInput.BASE)
                            return False

                        else:
                            self.throw_color_invalid_errror("Formatter", ErrColorInput.STATE)
                            return False

                if is_base_color:
                    self.base_color_in.set_r(channels_int[0])
                    self.base_color_in.set_g(channels_int[1])
                    self.base_color_in.set_b(channels_int[2])
                    self.base_color_in.set_a(channels_int[3])

                    self.color_indicator_base.setText(
                        "设置颜色成功\n"
                        "Color input is set."
                    )

                    self.color_indicator_base.setStyleSheet(
                        "QLabel { color: rgba(" + 
                        str(self.base_color_in.get_r()) + 
                        ", " +
                        str(self.base_color_in.get_g()) + 
                        ", " +
                        str(self.base_color_in.get_b()) + 
                        ", " +
                        str(self.base_color_in.get_a()) + 
                        "); font-weight: normal; }"
                    )

                else:
                    self.state_color_in.set_r(channels_int[0])
                    self.state_color_in.set_g(channels_int[1])
                    self.state_color_in.set_b(channels_int[2])
                    self.state_color_in.set_a(channels_int[3])

                    self.color_indicator_state.setText(
                        "设置颜色成功\n"
                        "Color input is set."
                    )

                    self.color_indicator_state.setStyleSheet(
                        "QLabel { color: rgba(" + 
                        str(self.state_color_in.get_r()) + 
                        ", " +
                        str(self.state_color_in.get_g()) + 
                        ", " +
                        str(self.state_color_in.get_b()) + 
                        ", " +
                        str(self.state_color_in.get_a()) + 
                        "); font-weight: normal; }"
                    )

        else:
            print("[INFO] Formatter - Detected format: HEX")
            input = input.upper()
            input = input.replace("#", "")
            print("[INFO] Formatter - Got Color input: #" + input + ".")

            if len(input) == 3 or len(input) == 4:
                input = self.normalize_hex(input)
            
            if len(input) < 6:
                if is_base_color:
                    self.throw_color_invalid_errror("Formatter", ErrColorInput.BASE)
                    return False

                else:
                    self.throw_color_invalid_errror("Formatter", ErrColorInput.STATE)
                    return False
                
            input_arr = self.split_hex_channel(input)
            try:
                if is_base_color:
                    self.base_color_in.set_r(int(input_arr[0], 16))
                    self.base_color_in.set_g(int(input_arr[1], 16))
                    self.base_color_in.set_b(int(input_arr[2], 16))
                    self.base_color_in.set_a(int(input_arr[3], 16))

                else:
                    self.state_color_in.set_r(int(input_arr[0], 16))
                    self.state_color_in.set_g(int(input_arr[1], 16))
                    self.state_color_in.set_b(int(input_arr[2], 16))
                    self.state_color_in.set_a(int(input_arr[3], 16))

            except ValueError:
                if is_base_color:
                    self.throw_color_invalid_errror("Formatter", ErrColorInput.BASE)
                    return False

                else:
                    self.throw_color_invalid_errror("Formatter", ErrColorInput.STATE)
                    return False
                
            if is_base_color:
                self.color_indicator_base.setText(
                    "设置颜色成功\n"
                    "Color input is set."
                )

                self.color_indicator_base.setStyleSheet(
                    "QLabel { color: rgba(" + 
                    str(self.base_color_in.get_r()) + 
                    ", " +
                    str(self.base_color_in.get_g()) + 
                    ", " +
                    str(self.base_color_in.get_b()) + 
                    ", " +
                    str(self.base_color_in.get_a()) + 
                    "); font-weight: normal; }"
                )

            else:
                self.color_indicator_state.setText(
                    "设置颜色成功\n"
                    "Color input is set."
                )

                self.color_indicator_state.setStyleSheet(
                    "QLabel { color: rgba(" + 
                    str(self.state_color_in.get_r()) + 
                    ", " +
                    str(self.state_color_in.get_g()) + 
                    ", " +
                    str(self.state_color_in.get_b()) + 
                    ", " +
                    str(self.state_color_in.get_a()) + 
                    "); font-weight: normal; }"
                )

        return True

    def normalize_hex(self, input):
        print("[WARN] HEX Normalizer: This function assume that your input is shorthand string format RGB or RGBA")
        input = input.replace("#", "")
        
        output = ""
        output += input[0]
        output += input[0]
        output += input[1]
        output += input[1]
        output += input[2]
        output += input[2]

        if len(input) == 4:
            output += input[3]
            output += input[3]

        print("[ OK ] HEX Normalizer: Generated HEX color " + output + ".")
        return output
    
    def split_hex_channel(self, input):
        print("[WARN] HEX Channel Splitter: This function assume that your input is shorthand string format RRGGBB or RRGGBBAA")
        output = ["", "", "", "FF"]
        
        output[0] = input[0:2]
        output[1] = input[2:4]
        output[2] = input[4:6]
        
        if len(input) >= 8:
            output[3] = input[6:8]

        print("[ OK ] HEX Channel Splitter: Successfully generated HEX color array.")
        return output
    
    def add_layer(self, base: int, layer: int):
        alpha = self.opacity_edit.value()
        result = base * (1 - alpha) + layer * alpha
        return min(round(result), 255)
    
    def generate_color(self):
        self.color_gen.set_r(self.add_layer(self.base_color_in.get_r(), self.state_color_in.get_r()))
        self.color_gen.set_g(self.add_layer(self.base_color_in.get_g(), self.state_color_in.get_g()))
        self.color_gen.set_b(self.add_layer(self.base_color_in.get_b(), self.state_color_in.get_b()))
        self.color_gen.set_a(self.add_layer(self.base_color_in.get_a(), self.state_color_in.get_a()))

        if self.auto_omit_alpha_check_box.isChecked() and self.color_gen.get_a() == 255:
            self.color_gen_hex = f"#{self.color_gen.get_r():02X}{self.color_gen.get_g():02X}{self.color_gen.get_b():02X}"
            self.color_hex.setText("<b>HEX</b>: " + self.color_gen_hex)
            self.copy_hex.show()

            self.color_gen_rgba = "rgb(" + str(self.color_gen.get_r()) +", " + str(self.color_gen.get_g()) + ", " + str(self.color_gen.get_b()) + ")"
            self.color_rgba.setText("<b>RGB</b>: " + self.color_gen_rgba)
            self.copy_rgba.show()

            self.color_preview.setStyleSheet("QLabel { background: " + self.color_gen_rgba + "; border: 1px solid " + self.color_gen_rgba + "; } ")

        else:
            self.color_gen_hex = f"#{self.color_gen.get_r():02X}{self.color_gen.get_g():02X}{self.color_gen.get_b():02X}{self.color_gen.get_a():02X}"
            self.color_hex.setText("<b>HEX</b>: " + self.color_gen_hex)
            self.copy_hex.show()

            self.color_gen_rgba = "rgba(" + str(self.color_gen.get_r()) +", " + str(self.color_gen.get_g()) + ", " + str(self.color_gen.get_b()) + ", " + str(self.color_gen.get_a()) + ")"
            self.color_rgba.setText("<b>RGBA</b>: " + self.color_gen_rgba)
            self.copy_rgba.show()

            self.color_preview.setStyleSheet("QLabel { background: " + self.color_gen_rgba + "; border: 1px solid " + self.color_gen_rgba + "; } ")

    def copy_hex_to_clipboard(self):
        QApplication.clipboard().setText(self.color_gen_hex)

    def copy_rgba_to_clipboard(self):
        QApplication.clipboard().setText(self.color_gen_rgba)

    def throw_color_invalid_errror(self, caller_name, type: ErrColorInput):
        print("[ERROR] " +  caller_name + ": The color you input is invalid. Hence, the function returned " + str(type.value) + ".")
        
        if type == ErrColorInput.BASE:
            self.color_indicator_base.setText("请检查输入的颜色是否有效\nPlease check if the color input is valid.")
            self.color_indicator_base.setStyleSheet("QLabel { color: red; font-weight: bold; }")

        else:
            self.color_indicator_state.setText("请检查输入的颜色是否有效\nPlease check if the color input is valid.")
            self.color_indicator_state.setStyleSheet("QLabel { color: red; font-weight: bold; }")


def main():
    app = QApplication(sys.argv)
    window = StateLayerCalculator()
    window.show()
    sys.exit(app.exec())

if __name__ == "__main__":
    main()