$(function(){
	$('#main').tabs();

	$('.formSubmit .button').button({
		icons: {
			primary:'ui-icon-trash'
		}
	});

$('form').each(function(){
	this.reset();
});

$('input[type="checkbox"][name^="unhidePassword"]').each(function(){
	var pass = $(this).attr('name').split('_')[1];
	$(this).disabled = false;

	if($(':checked', this)) {
		$(this).checked = false;
	}

	$(this).bind('change', function() {
		if($(':checked', this)) {
			document.getElementById(pass).type = 'text';
			document.getElementById(pass).focus();
			$(this).attr('disabled', 'disabled');
		}
	});
});

});
