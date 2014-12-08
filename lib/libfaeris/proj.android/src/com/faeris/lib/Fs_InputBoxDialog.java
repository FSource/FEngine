package com.faeris.lib; 

import android.app.Dialog;
import android.content.Context;
import android.graphics.drawable.ColorDrawable ;
import android.os.Bundle;
import android.os.Handler;
import android.text.InputFilter;
import android.text.InputType;
import android.util.TypedValue;
import android.view.KeyEvent;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;


public class Fs_InputBoxDialog extends Dialog 
{

	/* constants */

	private final int kInputModeAny=0;
	private final int kInputModeEmailAddr=1;
	private final int kInputModeNumeric=2;
	private final int kInputModePhoneNumber=3;
	private final int kInputModeUrl=4;
	private final int kInputModeDecimal=5;
	private final int kInputModeSingleLine=6;


	private final int kInputFlagPassword=0;
	private final int kInputFlagSensitive=1;
	private final int kInputFlagInitialCapsWord=2;
	private final int kInputFlagInitialCapsSentence=3;
	private final int kInputFlagInitialCapsAllCharacters=4;


	private final int kKeyboardReturnTypeDefault=0;
	private final int kKeyboardReturnTypeDone=1;
	private final int kKeyboardReturnTypeSend=2;
	private final int kKeyboardReturnTypeSearch=3;
	private final int kKeyboardReturnTypeGo=4;


	/* attr */
	private  EditText m_inputEditText;
	private  TextView m_textViewTitle;

	private final String m_title;
	private final String m_message;
	private final int m_inputMode;
	private final int m_inputFlag;
	private final int m_returnType;
	private final int m_maxLength;

	private int m_inputFlagConstraints;
	private int m_inputModeConstraints;
	private boolean m_isMultiline;

	public Fs_InputBoxDialog(final Context context,final String title,final String msg,
			final int input_mode,final int input_flag,final int return_type,final int max_length)
	{
		super(context,android.R.style.Theme_Translucent_NoTitleBar_Fullscreen);
		this.m_title=title;
		this.m_message=msg;
		this.m_inputMode=input_mode;
		this.m_inputFlag=input_flag;
		this.m_returnType=return_type;
		this.m_maxLength=max_length;
	}

	protected void onCreate(final Bundle saved_instance)
	{
		super.onCreate(saved_instance);
		this.getWindow().setBackgroundDrawable(new ColorDrawable(0x80000000));
		final LinearLayout layout=new LinearLayout(this.getContext());
		layout.setOrientation(LinearLayout.VERTICAL);


		/* text view */
		final LinearLayout.LayoutParams layout_params=new LinearLayout.LayoutParams(ViewGroup.LayoutParams.FILL_PARENT,ViewGroup.LayoutParams.FILL_PARENT);

		this.m_textViewTitle=new TextView(this.getContext());
		final LinearLayout.LayoutParams textview_params=new LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT,ViewGroup.LayoutParams.WRAP_CONTENT);

		textview_params.leftMargin=textview_params.rightMargin=this.convertDipsToPixels(10);
		this.m_textViewTitle.setTextSize(TypedValue.COMPLEX_UNIT_DIP,20);
		layout.addView(this.m_textViewTitle,textview_params);


		/* input text */
		this.m_inputEditText=new EditText(this.getContext());
		final LinearLayout.LayoutParams edit_text_params=new LinearLayout.LayoutParams(ViewGroup.LayoutParams.FILL_PARENT,ViewGroup.LayoutParams.WRAP_CONTENT);
		edit_text_params.leftMargin=edit_text_params.rightMargin=this.convertDipsToPixels(10);
		layout.addView(this.m_inputEditText,edit_text_params);

		this.setContentView(layout,edit_text_params);
		this.getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
		this.m_textViewTitle.setText(this.m_title);
		this.m_inputEditText.setText(this.m_message);

		int old_ime_options=this.m_inputEditText.getImeOptions();
		this.m_inputEditText.setImeOptions(old_ime_options|EditorInfo.IME_FLAG_NO_EXTRACT_UI);
		old_ime_options=this.m_inputEditText.getImeOptions();



		switch (this.m_inputMode) 
		{
			case kInputModeAny:
				this.m_inputModeConstraints = InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_FLAG_MULTI_LINE;
				break;
			case kInputModeEmailAddr:
				this.m_inputModeConstraints = InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_EMAIL_ADDRESS;
				break;
			case kInputModeNumeric:
				this.m_inputModeConstraints = InputType.TYPE_CLASS_NUMBER | InputType.TYPE_NUMBER_FLAG_SIGNED;
				break;
				case kInputModePhoneNumber:
					this.m_inputModeConstraints = InputType.TYPE_CLASS_PHONE;
				break;
			case kInputModeUrl:
				this.m_inputModeConstraints = InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_URI;
				break;
			case kInputModeDecimal:
				this.m_inputModeConstraints = InputType.TYPE_CLASS_NUMBER | InputType.TYPE_NUMBER_FLAG_DECIMAL | InputType.TYPE_NUMBER_FLAG_SIGNED;
				break;
			case kInputModeSingleLine:
				this.m_inputModeConstraints = InputType.TYPE_CLASS_TEXT;
				break;
			default:
				break;
		}
		if(this.m_isMultiline) 
		{
			this.m_inputModeConstraints |=InputType.TYPE_TEXT_FLAG_MULTI_LINE;
		}

		this.m_inputEditText.setInputType(this.m_inputModeConstraints|this.m_inputFlagConstraints);

		switch(this.m_inputFlag)
		{
			case kInputFlagPassword:
				this.m_inputFlagConstraints = InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_PASSWORD;
				break;
			case kInputFlagSensitive:
				this.m_inputFlagConstraints = InputType.TYPE_TEXT_FLAG_NO_SUGGESTIONS;
				break;
			case kInputFlagInitialCapsWord:
				this.m_inputFlagConstraints = InputType.TYPE_TEXT_FLAG_CAP_WORDS;
				break;
			case kInputFlagInitialCapsSentence:
				this.m_inputFlagConstraints = InputType.TYPE_TEXT_FLAG_CAP_SENTENCES;
				break;
			case kInputFlagInitialCapsAllCharacters:
				this.m_inputFlagConstraints = InputType.TYPE_TEXT_FLAG_CAP_CHARACTERS;
				break;
			default:
				break;
		}


		this.m_inputEditText.setInputType(this.m_inputFlagConstraints | this.m_inputModeConstraints);

		switch (this.m_returnType) {
			case kKeyboardReturnTypeDefault:
				this.m_inputEditText.setImeOptions(old_ime_options | EditorInfo.IME_ACTION_NONE);
				break;
			case kKeyboardReturnTypeDone:
				this.m_inputEditText.setImeOptions(old_ime_options | EditorInfo.IME_ACTION_DONE);
				break;
			case kKeyboardReturnTypeSend:
				this.m_inputEditText.setImeOptions(old_ime_options | EditorInfo.IME_ACTION_SEND);
				break;
			case kKeyboardReturnTypeSearch:
				this.m_inputEditText.setImeOptions(old_ime_options | EditorInfo.IME_ACTION_SEARCH);
				break;
			case kKeyboardReturnTypeGo:
				this.m_inputEditText.setImeOptions(old_ime_options | EditorInfo.IME_ACTION_GO);
				break;
			default:
				this.m_inputEditText.setImeOptions(old_ime_options | EditorInfo.IME_ACTION_NONE);
				break;
		}

		if(this.m_maxLength>0)
		{
			this.m_inputEditText.setFilters(new InputFilter[]{new InputFilter.LengthFilter(this.m_maxLength)});
		}

		final Handler init_handler=new Handler();
		init_handler.postDelayed(new Runnable() {
			public void run() {
				Fs_InputBoxDialog.this.m_inputEditText.requestFocus();
				Fs_InputBoxDialog.this.m_inputEditText.setSelection(Fs_InputBoxDialog.this.m_inputEditText.length());
				Fs_InputBoxDialog.this.openKeyboard();
			}
		},200);

		this.m_inputEditText.setOnEditorActionListener( new OnEditorActionListener() {
			public boolean onEditorAction(final TextView v,final int actionid,final KeyEvent event)
		{
			if(actionid != EditorInfo.IME_NULL || (actionid==EditorInfo.IME_NULL && event!=null && event.getAction()==KeyEvent.ACTION_DOWN))
		{
				
			Fs_Application.runOnEngineThread(new Runnable(){
				public void run(){
					Fs_Jni.onInputText(Fs_InputBoxDialog.this.m_inputEditText.getText().toString());
			}
			});
		


			Fs_InputBoxDialog.this.closeKeyboard();
			Fs_InputBoxDialog.this.dismiss();
			return true;
		}
		return false;

		}
		});
	}

	private int convertDipsToPixels(final float dips)
	{
		final float scale=this.getContext().getResources().getDisplayMetrics().density;
		return Math.round(dips*scale);
	}

	private void openKeyboard()
	{
		final InputMethodManager imm=(InputMethodManager) this.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
		imm.showSoftInput(this.m_inputEditText,0);
	}

	private void closeKeyboard()
	{
		final InputMethodManager imm=(InputMethodManager) this.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
		imm.hideSoftInputFromWindow(this.m_inputEditText.getWindowToken(),0);
	}

}












