extends MultiClientUI;
class_name SimpleMultiClientUI;

@export var _regex_line_edit: RegexLineEdit;
@export var _submit_button: Button;
@export var _clear_button: Button;

func _ready() -> void:
	_submit_button.pressed.connect(_on_submit_pressed);
	_clear_button.pressed.connect(_on_clear_pressed);
	
func _on_submit_pressed() -> void:
	var clients_to_spawn: int = int(_regex_line_edit.text);
	if clients_to_spawn <= 0 || clients_to_spawn > 5:
		return;
	
	create_clients(clients_to_spawn);

func _on_clear_pressed() -> void:
	kill_clients();
